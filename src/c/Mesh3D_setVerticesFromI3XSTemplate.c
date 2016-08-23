/*
   Package: Mesh3D
   File   : Mesh3D_setVerticesFromI3XSTemplate.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 23 2016
*/

#include "Mesh3D.h"


void
Mesh3D_setVerticesFromI3XSTemplate
( Mesh3D               *mesh
, const I3XS_PointInfo *template
, const float           size
)
{
  const unsigned int verticesNum    = mesh->verticesNum = template->pointsNum ;
  const float        scale          = 0.5 * size / I3XS_MAXABS ;
  const I3XS        *templatePoints = template->points ;
  Vertex            *vertices       = mesh->vertices ;

  for ( unsigned int vIdx = 0  ;  vIdx < verticesNum  ;  ++vIdx )
    R3_set( &vertices[vIdx].worldCoord
          , scale * templatePoints[vIdx].x    // x
          , scale * templatePoints[vIdx].y    // y
          , scale * templatePoints[vIdx].z    // z
          ) ;
}