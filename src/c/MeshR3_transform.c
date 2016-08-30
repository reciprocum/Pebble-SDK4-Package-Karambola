/*
   Package: MeshR3
   File   : MeshR3_transform.c
   Author : Afonso Santos, Portugal

   Last revision: 11h25 August 30 2016
*/

#include "Matrix34.h"
#include "MeshR3.h"


void
MeshR3_transform
( MeshR3    *this
, const R3   rotation      // 3D rotation.
, const R3   translation   // 3D translation.
)
{
  Matrix34 transformationMtx ;
  Matrix34_transformation( &transformationMtx, rotation, translation ) ;

  // rotate the mesh normal.
  Matrix34_rotate( this->normal_worldCoord, this->normal_worldCoord, &transformationMtx ) ;

  const int     verticesNum = this->verticesNum ;
        Vertex *vertices    = this->vertices ;

  // transform the vertices.
  for (int vIdx = 0  ;  vIdx < verticesNum  ;  ++vIdx)
  {
    R3 *v = &vertices[vIdx].worldCoord ;
    Matrix34_transform( v, v, &transformationMtx ) ;
  }
}