/*
   Package: MeshR3
   File   : MeshR3_setFromI2XSTemplate.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 30 2016
*/

#include "MeshR3.h"


void
MeshR3_setFromI2XSTemplate
( MeshR3              *this
, const I2_8_PathInfo *verticesInfo
, const EdgeInfo      *edgeInfo
, const R2             size
, const R2             position
)
{
  const int    verticesNum    = this->verticesNum = verticesInfo->pointsNum ;
  const float  scaleX         = 0.5f * size.x / I2_8_MAXABS ;
  const float  scaleY         = 0.5f * size.y / I2_8_MAXABS ;
  const I2_8  *templatePoints = verticesInfo->points ;
  Vertex      *vertices       = this->vertices ;

  for (int vIdx = 0  ;  vIdx < verticesNum  ;  ++vIdx)
    R3_set( &vertices[vIdx].worldCoord
          , scaleX * templatePoints[vIdx].x + position.x    // x
          , scaleY * templatePoints[vIdx].y + position.y    // y
          , 0.0f                                            // z
          ) ;

  // set the mesh normal.
  R3_assign( this->normal_worldCoord, &R3_versorMinusZ ) ;

  this->edgeInfo = edgeInfo ;
}