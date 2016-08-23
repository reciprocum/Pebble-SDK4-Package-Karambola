/*
   Package: Mesh3D
   File   : Mesh3D_setVerticesFromI2XSTemplate.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 23 2016
*/

#include "Mesh3D.h"


void
Mesh3D_setVerticesFromI2XSTemplate
( Mesh3D                *mesh
, const I2_8_PathInfo *template
, const float          width
, const float          height
, const float          shiftX
)
{
  const unsigned int verticesNum    = mesh->verticesNum = template->pointsNum ;
  const float        aX             = 0.5 * width  / I2_8_MAXABS ;
  const float        aY             = 0.5 * height / I2_8_MAXABS ;
  const I2_8        *templatePoints = template->points ;
  Vertex            *vertices       = mesh->vertices ;

  for ( unsigned int vIdx = 0  ;  vIdx < verticesNum  ;  ++vIdx )
    R3_set( &vertices[vIdx].worldCoord
          , aX * templatePoints[vIdx].x + shiftX    // x
          , aY * templatePoints[vIdx].y             // y
          , 0                                       // z
          ) ;

  // set the mesh normal.
  R3_assign( mesh->normal_worldCoord, &R3_versorMinusZ ) ;
}