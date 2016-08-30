/*
   Package: MeshR3
   File   : MeshR3_calculateFaceNormals.c
   Author : Afonso Santos, Portugal

   Last revision: 17h45 August 29 2016
*/

#include "MeshR3.h"


// Calculate the normal vector from the first 2 edges of each face.
// TODO: extend to work properly even if first 2 edges are parallel to each other.
void
MeshR3_calculateFaceNormals
( MeshR3 *this )
{
  if (this == NULL)
    return ;
  
  if (this->edgeInfo == NULL)
    return ;

  const Vertex *vertices = this->vertices ;
  const Edge   *edges    = this->edgeInfo->edges ;
  const int     facesNum = this->facesNum ;
        Face   *faces    = this->faces ;

  for (int fIdx = 0 ; fIdx < facesNum ; ++fIdx)
  {
    Face               *f               = &faces[fIdx] ;
    const uint16_t     *faceEdgeIndexes = f->faceInfo->edgeIndexes ;
    const unsigned int  e0_idx          = faceEdgeIndexes[0] ;
    R3                  e0_v1v2 ;

    R3_sub( &e0_v1v2
          , &vertices[edges[e0_idx].v1].worldCoord
          , &vertices[edges[e0_idx].v2].worldCoord
          ) ;

    unsigned int e1_idx = faceEdgeIndexes[1] ;
    R3 e1_v1v2 ;

    R3_sub( &e1_v1v2
          , &vertices[edges[e1_idx].v1].worldCoord
          , &vertices[edges[e1_idx].v2].worldCoord
          ) ;

    R3_crossProduct( &f->normal_worldCoord, &e0_v1v2, &e1_v1v2 ) ;
  }
}