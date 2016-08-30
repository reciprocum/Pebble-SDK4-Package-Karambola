/*
   Package: MeshR3
   File   : MeshR3_setFromI3XSTemplate.c
   Author : Afonso Santos, Portugal

   Last revision: 11h55 August 30 2016
*/

#include "MeshR3.h"


void
MeshR3_setFromI3XSTemplate
( MeshR3               *this
, const I3XS_PointInfo *vertexInfo
, const EdgeInfo       *edgeInfo
, const R3              size
, const R3              position
)
{
  const int      verticesNum    = this->verticesNum = vertexInfo->pointsNum ;
  const float    scaleX         = 0.5f * size.x / I3XS_MAXABS ;
  const float    scaleY         = 0.5f * size.y / I3XS_MAXABS ;
  const float    scaleZ         = 0.5f * size.z / I3XS_MAXABS ;
  const I3XS    *templatePoints = vertexInfo->points ;
        Vertex  *vertices       = this->vertices ;

  for (int vIdx = 0  ;  vIdx < verticesNum  ;  ++vIdx)
    R3_set( &vertices[vIdx].worldCoord
          , scaleX * templatePoints[vIdx].x  +  position.x   // x
          , scaleY * templatePoints[vIdx].y  +  position.y   // y
          , scaleZ * templatePoints[vIdx].z  +  position.z   // z
          ) ;

  this->edgeInfo = edgeInfo ;
}