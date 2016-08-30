/*
   Package: CubeR3 - float based vertices implementation of a 3D cube mesh.
   File   : CubeR3.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 30 2016
*/

#include "Cube.h"
#include "MeshR3.h"


MeshR3*
CubeR3_new
( )
{
  return MeshR3_new( CUBE_VERTEXINFO.pointsNum   // # of vertices
                   , CUBE_EDGEINFO.edgesNum      // # of edges
                   , 6                           // # of faces
                   ) ;
}


void
CubeR3_config
( MeshR3      *this          // Cube mesh being configured.
, const float  size
, Blinker     *inkBlinker
)
{
  if (this == NULL)
    return ;

  this->inkBlinker = inkBlinker ;

  MeshR3_setFromI3XSTemplate( this
                            , &CUBE_VERTEXINFO
                            , &CUBE_EDGEINFO
                            , (R3){ .x = size, .y = size, .z = size }
                            , R3_origin                                 // Position
                            ) ;

  // Set faces.
  this->faces[0].faceInfo = &CUBE_FACE0 ;
  this->faces[1].faceInfo = &CUBE_FACE1 ;
  this->faces[2].faceInfo = &CUBE_FACE2 ;
  this->faces[3].faceInfo = &CUBE_FACE3 ;
  this->faces[4].faceInfo = &CUBE_FACE4 ;
  this->faces[5].faceInfo = &CUBE_FACE5 ;

  MeshR3_calculateFaceNormals( this ) ;
}