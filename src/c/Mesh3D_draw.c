/*
   Package: Mesh3D
   File   : Mesh3D_draw.c
   Author : Afonso Santos, Portugal

   Last revision: 14h05 August 22 2016
*/

#include "Config.h"
#include "Binary.h"
#include "Mesh3D.h"


void
Mesh3D_draw
( GContext                      *gCtx
, Mesh3D                        *mesh
, const Cam3D                   *cam
, const int                      w
, const int                      h
, const Mesh3D_TransparencyMode  transparency
)
{
  if ( (mesh == NULL)
    || (mesh->edgeInfo == NULL)
    || (mesh->state.isDisabled)
     )
    return ;

  const unsigned int   verticesNum = mesh->verticesNum ;
  const unsigned int   edgesNum    = mesh->edgeInfo->edgesNum ;
  const unsigned int   facesNum    = mesh->facesNum ;
  Vertex              *vertices    = mesh->vertices ;
  Edge                *edges       = mesh->edgeInfo->edges ;
  ViewFlags           *edgesState  = mesh->edgesState ;
  Face                *faces       = mesh->faces ;

  // Assert visibility of edges.
  switch (transparency)
  {
    case MESH3D_TRANSPARENCY_WIREFRAME:                    // All edges are visible in this mode.
      for ( unsigned int me = 0 ; me < edgesNum ; ++me )
        edgesState[me].isHidden = false ;

      break ;                                               // No need to waste time with normal vectors, etc.

    case MESH3D_TRANSPARENCY_SOLID:
    case MESH3D_TRANSPARENCY_XRAY:
    default :
      if (mesh->normal_worldCoord)
        { // Planar mesh: determine its visibility from its normal vector. Use any vertex as anchor for normal.
          R3 towardsMesh3D_normalAnchor ;
          R3_sub( &towardsMesh3D_normalAnchor, &vertices[0].worldCoord, &cam->viewPoint) ;
          const bool meshIsVisible = (R3_dotProduct( mesh->normal_worldCoord, &towardsMesh3D_normalAnchor) < 0.0) ;

          for ( unsigned int me = 0 ; me < edgesNum ; ++me )    // Mark all this meshe's edges with mesh visibility result.
              edgesState[me].isHidden = meshIsVisible ;
        }
        else   // Non-planar mesh: face-by-face visibility assertion.
        { // #1: Assume/mark all mesh edges as invisible.
          for ( unsigned int me = 0 ; me < edgesNum ; ++me )
            edgesState[me].isHidden = true ;

          // #2: Iterate all faces and mark all edges of visible faces as visible edges.
          for ( uint8_t mf = 0 ; mf < facesNum ; ++mf )
          {
            const Face *f = &faces[mf] ;
            
            if (f->state.isDisabled)
              continue ;     // Skip disabled faces (all their edges will remain hidden unless they also belong to another face).

            // Get any point from the face (to serve as anchor for normal vector).
            // We settle with the first vertex of the first edge (of the current face).
            const R3 *anchorOfFaceNormal = &vertices[edges[f->faceInfo->edgeIndexes[0]].v1].worldCoord ;
        
            // Cast a vector from the camera's view point towards the face's normal anchor point ...
            // ... and use dot product with face normal to determine face visibility.
            R3 towardsFaceAnchor ;
            R3_sub( &towardsFaceAnchor, anchorOfFaceNormal, &cam->viewPoint) ;

            if (R3_dotProduct( &f->normal_worldCoord, &towardsFaceAnchor) < 0.0)
            {
              const unsigned int  faceEdgesNum    = f->faceInfo->edgesNum ;
              const uint16_t     *faceEdgeIndexes = f->faceInfo->edgeIndexes ;

              for ( unsigned int fe = 0 ; fe < faceEdgesNum ; ++fe )    // Mark all this face's edges as visible.
                edgesState[faceEdgeIndexes[fe]].isHidden = false ;
            }
          }
        }
  } // switch (transparency)

  // Assert visibility of vertices.
  switch (transparency)
  {
    case MESH3D_TRANSPARENCY_WIREFRAME:                  // All vertices are plotted in these 2 modes.
    case MESH3D_TRANSPARENCY_XRAY:
      for ( unsigned int mv = 0 ; mv < verticesNum ; ++mv )
        vertices[mv].state.isHidden = false ;

      break ;

    case MESH3D_TRANSPARENCY_SOLID:                      // Only vertices bellonging to visible edges need to be plotted.
    default :
      // Initialize all vertices as being not visible.
      for ( unsigned int mv = 0 ; mv < verticesNum ; ++mv )
        vertices[mv].state.isHidden = true ;

      // Vertices that belong to visible edges are visible themselfs.
      for ( unsigned int me = 0 ; me < edgesNum ; ++me )
      {
        const ViewFlags *edgeState = &edgesState[me] ;

        if ( !edgeState->isDisabled
          && !edgeState->isHidden
           )
        { // Both vertices of this edge are visible.
          const Edge *e = &edges[me] ;
          vertices[e->v1].state.isHidden = false ;
          vertices[e->v2].state.isHidden = false ;
        }
      }
  }
    
  // View mesh: calculates device coordinates of visible vertices.
  {
    const uint8_t  k = ( w > h ) ?  h : w ;
    const uint8_t  bX = w >> 1 ;
    const uint8_t  bY = h >> 1 ;

    for( unsigned int mv = 0  ;  mv < verticesNum  ;  ++mv )
    {
      const Vertex *v = &vertices[mv] ;

      if (!v->state.isHidden)   // Skip hidden vertices.
      {
        // calculate screen coordinates of visible vertex.
        R2 vCamera ;
        Cam3D_view( &vCamera, cam, &v->worldCoord ) ;
  
        // calculate device coordinates of vertex.
        __Mesh3D_vertex_screenPoint[mv].x = k * vCamera.x  +  bX ;
        __Mesh3D_vertex_screenPoint[mv].y = k * vCamera.y  +  bY ;
      }
    }
  }

  // Calculate the plotting inks.
  ink_t inkVisible = (mesh->inkBlinker != NULL ? mesh->inkBlinker->value : INK100 ) ;
  ink_t inkHidden ;

  switch (transparency)
  {
    case MESH3D_TRANSPARENCY_XRAY:
      inkHidden = INK33 ;                 // Dimmed to 33% brightness.
      break ;

    case MESH3D_TRANSPARENCY_WIREFRAME:
      inkHidden = inkVisible ;            // Fully visible.
      break ;

    case MESH3D_TRANSPARENCY_SOLID:
    default :
      inkHidden = INK0 ;                  // Not visible.
      break ;
  }

  const bool hasAlternateEdges = (mesh->edgeAlternateMask_L2R != NULL) ;

  if (!hasAlternateEdges)
  {
#ifdef PBL_COLOR
    graphics_context_set_stroke_color( gCtx, mesh->strokeColor ) ;
#else
    graphics_context_set_stroke_color( gCtx, GColorWhite ) ;
#endif

    graphics_context_set_stroke_width( gCtx, mesh->strokeWidth ) ;
  }

  // Plots the (non disabled & visible) mesh edges.
  for ( unsigned int me = 0  ;  me < edgesNum  ;  ++me )
    if (!edgesState[me].isDisabled)  // Skip disabled edges.
    {
      if (hasAlternateEdges)
      {
        if (Binary_isSetL2R( mesh->edgeAlternateMask_L2R, me ))
        {
#ifdef PBL_COLOR
          graphics_context_set_stroke_color( gCtx, mesh->strokeColorAlternate ) ;
#else
          graphics_context_set_stroke_color( gCtx, GColorWhite ) ;
#endif

          graphics_context_set_stroke_width( gCtx, mesh->strokeWidthAlternate ) ;
        }
        else
        {
#ifdef PBL_COLOR
          graphics_context_set_stroke_color( gCtx, mesh->strokeColor ) ;
#else
          graphics_context_set_stroke_color( gCtx, GColorWhite ) ;
#endif

          graphics_context_set_stroke_width( gCtx, mesh->strokeWidth ) ;
        }
      }

      const GPoint p0 = __Mesh3D_vertex_screenPoint[edges[me].v1] ;
      const GPoint p1 = __Mesh3D_vertex_screenPoint[edges[me].v2] ;

      //draw v1-v2 2D line.
#ifdef QEMU
      // QEMU cannot cope with the workload of antialising, so have to use non-native/alternative line drawing method instead.
      Draw2D_line( gCtx, p0.x, p0.y, p1.x, p1.y, edgesState[me].isHidden ? inkHidden : inkVisible ) ;
#else
      // Running on a real watch.
      if (edgesState[me].isHidden)
        Draw2D_line( gCtx, p0.x, p0.y, p1.x, p1.y, inkHidden ) ;   // Hidden lines are drawned without antialising.
      else
        graphics_draw_line( gCtx, p0, p1 ) ;                       // Visible lines are drawned antialised and with stroke width.
#endif
    }
}