/*
   Package: Mesh3D
   File   : Mesh3D.h
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 23 2016
*/

#pragma once

#include "I2_8.h"
#include "I3.h"
#include "R3.h"
#include "Edge.h"
#include "Draw2D.h"
#include "Cam3D.h"
#include "Blinker.h"


typedef enum { MESH3D_TRANSPARENCY_SOLID
             , MESH3D_TRANSPARENCY_XRAY
             , MESH3D_TRANSPARENCY_WIREFRAME
             }
Mesh3D_TransparencyMode ;


typedef struct
{ 
  R3         worldCoord ;   // World (scaled, rotated, translated) coordinates.
  ViewFlags  state ;        // Used to remember/optimize vertex visibility (from a camera viewpoint).
} Vertex ;


typedef struct
{
  uint16_t  edgesNum ;
  uint16_t *edgeIndexes ;
} FaceInfo ;


typedef struct
{ 
  const FaceInfo *faceInfo ;
  R3              normal_worldCoord ;   // Used to determine face visibility (from a camera viewpoint towards any vertice of any edge of the face).
  ViewFlags       state ;               // Used to remember/optimize face visibility (determined from normal vector).
} Face ;


typedef struct
{ // vertices
  uint16_t         verticesNum ;
  Vertex          *vertices ;

  // edges
  const EdgeInfo  *edgeInfo ;
  ViewFlags       *edgesState ;

  // faces
  uint16_t         facesNum ;
  Face            *faces ;

  R3                  *normal_worldCoord ;  // Optional (used only in planar meshes): used to determine mesh visibility (if defined).
  ViewFlags            state ;
  Blinker             *inkBlinker ;
  uint8_t              strokeWidth ;
  GColor               strokeColor ;
  uint8_t              strokeWidthAlternate ;
  GColor               strokeColorAlternate ;
  const unsigned char *edgeAlternateMask_L2R ;      // BitString mask of wich edges use the edgeStroke[Width|Color]]Alternate properties.
} Mesh3D ;


Mesh3D*  Mesh3D_free( Mesh3D *mesh ) ;
Mesh3D*  Mesh3D_new( const uint16_t verticesNum, const uint16_t edgesNum, const uint16_t facesNum ) ;

// Calculate the normal vector from the first 2 edges of each face.
void  Mesh3D_calculateFaceNormals( Mesh3D *mesh ) ;

void
Mesh3D_setVerticesFromI2XSTemplate
( Mesh3D              *mesh
, const I2_8_PathInfo *template
, const float          width
, const float          height
, const float          shiftX
) ;

void
Mesh3D_setVerticesFromI3XSTemplate
( Mesh3D               *mesh
, const I3XS_PointInfo *template
, const float           size
) ;

void
Mesh3D_setFromI2XSTemplate
( Mesh3D              *mesh
, const I2_8_PathInfo *verticesInfo
, const EdgeInfo      *edgeInfo
, const float          width
, const float          height
, const float          shiftX2D
, const float          rotationX
, const float          rotationY
, const float          rotationZ
, const R3            *anchor3D
) ;

void
Mesh3D_setFromI3XSTemplate
( Mesh3D               *mesh
, const I3XS_PointInfo *vertexInfo
, const EdgeInfo       *edgeInfo
, const float           size
, const float           rotationX
, const float           rotationY
, const float           rotationZ
, const R3             *anchor3D
) ;

void
Mesh3D_transform
( Mesh3D      *mesh
, const float  rotationX
, const float  rotationY
, const float  rotationZ
, const R3    *anchor3D
) ;

// This variable is critical to the draw algorithm.
// Used to pre-calculate (only once per vertex) the screen coordinates of the vertexes (after 3D->2D camera projected).
// MUST be provided (and adequately dimensioned to the MAX number of vertexes of all the meshes) by main.c
extern GPoint __Mesh3D_vertex_screenPoint[] ;

void
Mesh3D_draw
( GContext                      *gCtx
, Mesh3D                        *mesh
, const Cam3D                   *cam
, const int                      w
, const int                      h
, const Mesh3D_TransparencyMode  transparency
) ;