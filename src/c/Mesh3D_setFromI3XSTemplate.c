/*
   Package: Mesh3D
   File   : Mesh3D_setFromI3XSTemplate.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 23 2016
*/

#include "Mesh3D.h"


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
)
{
  Mesh3D_setVerticesFromI3XSTemplate( mesh, vertexInfo, size ) ;
  mesh->edgeInfo = edgeInfo ;
  Mesh3D_transform( mesh, rotationX, rotationY, rotationZ, anchor3D ) ;
}