/*
   Package: MeshR3
   File   : MeshR3.h
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 30 2016
*/

#pragma once

#include "I2_8.h"
#include "I3.h"
#include "R3.h"
#include "Edge.h"
#include "Mesh.h"
#include "Draw2D.h"
#include "CamR3.h"
#include "Blinker.h"


typedef struct
{ 
  R3         worldCoord ;   // World (scaled, rotated, translated) coordinates.
  ViewFlags  state ;        // Used to remember/optimize vertex visibility (from a camera viewpoint).
} Vertex ;


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
} MeshR3 ;


MeshR3*  MeshR3_free( MeshR3 *this ) ;
MeshR3*  MeshR3_new( const uint16_t verticesNum, const uint16_t edgesNum, const uint16_t facesNum ) ;

// Calculate the normal vector from the first 2 edges of each face.
void  MeshR3_calculateFaceNormals( MeshR3 *this ) ;

void
MeshR3_setFromI2XSTemplate
( MeshR3              *this
, const I2_8_PathInfo *verticesInfo
, const EdgeInfo      *edgeInfo
, const R2             size
, const R2             position
) ;

void
MeshR3_setFromI3XSTemplate
( MeshR3               *this
, const I3XS_PointInfo *vertexInfo
, const EdgeInfo       *edgeInfo
, const R3              size
, const R3              position
) ;

void
MeshR3_transform
( MeshR3    *mesh
, const R3   rotation      // 3D rotation.
, const R3   translation   // 3D translation.
) ;

// This variable is critical to the draw algorithm.
// Used to pre-calculate (only once per vertex) the screen coordinates of the vertexes (after 3D->2D camera projected).
// MUST be provided (and adequately dimensioned to the MAX number of vertexes of all the meshes) by main.c
extern GPoint __MeshR3_vertex_screenPoint[] ;

void
MeshR3_draw
( GContext               *gCtx
, MeshR3                 *this
, const CamR3            *cam
, const int               w
, const int               h
, const MeshTransparency  transparency
) ;