/*
   Package: MeshQ3
   File   : MeshQ3_setFromI3XSTemplate.c
   Author : Afonso Santos, Portugal

   Last revision: 11h55 August 30 2016
*/

#include "Config.h"
#include "MeshQ3.h"


void
MeshQ3_setFromI3XSTemplate
( MeshQ3               *this
, const I3XS_PointInfo *vertexInfo
, const EdgeInfo       *edgeInfo
, const Q3              size
, const Q3              position
)
{
  const Q  normalize = Q_make(I3XS_MAXABS) << 1 ;    // 2.0f * I3XS_MAXABS

  const Q  scaleX    = Q_div( size.x, normalize ) ;
  const Q  scaleY    = Q_div( size.y, normalize ) ;
  const Q  scaleZ    = Q_div( size.z, normalize ) ;

  const I3XS    *templatePoints = vertexInfo->points ;
        Vertex  *vertices       = this->vertices ;
  const int      verticesNum    = this->verticesNum = vertexInfo->pointsNum ;

  for (int vIdx = 0  ;  vIdx < verticesNum  ;  ++vIdx)
    Q3_set( &vertices[vIdx].worldCoord
          , Q_mul( scaleX, Q_make(templatePoints[vIdx].x) )  +  position.x
          , Q_mul( scaleY, Q_make(templatePoints[vIdx].y) )  +  position.y
          , Q_mul( scaleZ, Q_make(templatePoints[vIdx].z) )  +  position.z
          ) ;

  this->edgeInfo = edgeInfo ;
}