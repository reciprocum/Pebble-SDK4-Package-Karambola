/*
   Package: Mesh3D
   File   : Mesh3D_setFromI2XSTemplate.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 23 2016
*/

#include "Mesh3D.h"


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
)
{
  Mesh3D_setVerticesFromI2XSTemplate( mesh, verticesInfo, width, height, shiftX2D ) ;
  mesh->edgeInfo = edgeInfo ;
  Mesh3D_transform( mesh, rotationX, rotationY, rotationZ, anchor3D ) ;
}