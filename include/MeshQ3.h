/*
   Package: MeshQ3
   File   : MeshQ3.h
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 30 2016
*/

#pragma once

#include "I2_8.h"
#include "I3.h"
#include "Q3.h"
#include "Edge.h"
#include "Mesh.h"
#include "Draw2D.h"
#include "CamQ3.h"
#include "Blinker.h"


typedef struct
{ 
  Q3         worldCoord ;   // World (scaled, rotated, translated) coordinates.
  ViewFlags  state ;        // Used to remember/optimize vertex visibility (from a camera viewpoint).
} Vertex ;


typedef struct
{ 
  const FaceInfo *faceInfo ;
  Q3              normal_worldCoord ;   // Used to determine face visibility (from a camera viewpoint towards any vertice of any edge of the face).
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

  Q3                  *normal_worldCoord ;  // Optional (used only in planar meshes): used to determine mesh visibility (if defined).
  ViewFlags            state ;
  Blinker             *inkBlinker ;
  uint8_t              strokeWidth ;
  GColor               strokeColor ;
  uint8_t              strokeWidthAlternate ;
  GColor               strokeColorAlternate ;
  const unsigned char *edgeAlternateMask_L2R ;      // BitString mask of wich edges use the edgeStroke[Width|Color]]Alternate properties.
} MeshQ3 ;


MeshQ3*  MeshQ3_free( MeshQ3 *this ) ;
MeshQ3*  MeshQ3_new( const uint16_t verticesNum, const uint16_t edgesNum, const uint16_t facesNum ) ;

// Calculate the normal vector from the first 2 edges of each face.
void  MeshQ3_calculateFaceNormals( MeshQ3 *this ) ;

void
MeshQ3_setFromI2XSTemplate
( MeshQ3              *this
, const I2_8_PathInfo *verticesInfo
, const EdgeInfo      *edgeInfo
, const Q2             size
, const Q2             position
) ;

void
MeshQ3_setFromI3XSTemplate
( MeshQ3               *this
, const I3XS_PointInfo *vertexInfo
, const EdgeInfo       *edgeInfo
, const Q3              size
, const Q3              position
) ;

void
MeshQ3_transform
( MeshQ3    *mesh
, const Q3   rotation      // 3D rotation.
, const Q3   translation   // 3D translation.
) ;

// This variable is critical to the draw algorithm.
// Used to pre-calculate (only once per vertex) the screen coordinates of the vertexes (after 3D->2D camera projected).
// MUST be provided (and adequately dimensioned to the MAX number of vertexes of all the meshes) by main.c
extern GPoint __MeshQ3_vertex_screenPoint[] ;

void
MeshQ3_draw
( GContext               *gCtx
, MeshQ3                 *this
, const CamQ3            *cam
, const int               w
, const int               h
, const MeshTransparency  transparency
) ;