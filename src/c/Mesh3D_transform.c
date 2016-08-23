/*
   Package: Mesh3D
   File   : Mesh3D_transform.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 23 2016
*/

#include "Matrix34.h"
#include "Mesh3D.h"


void
Mesh3D_transform
( Mesh3D      *mesh
, const float  rotationX
, const float  rotationY
, const float  rotationZ
, const R3    *anchor3D
)
{
  Matrix34 transformationMtx ;
  Matrix34_transformation( &transformationMtx, rotationX, rotationY, rotationZ, anchor3D ) ;

  // rotate the mesh normal.
  Matrix34_rotate( mesh->normal_worldCoord, mesh->normal_worldCoord, &transformationMtx ) ;

  const unsigned int verticesNum = mesh->verticesNum ;
  Vertex            *vertices    = mesh->vertices ;

  // transform the vertices.
  for ( unsigned int vIdx = 0  ;  vIdx < verticesNum  ;  ++vIdx )
  {
    R3 *v = &vertices[vIdx].worldCoord ;
    Matrix34_transform( v, v, &transformationMtx ) ;
  }
}