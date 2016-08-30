/*
   Package: CubeQ3 - float based vertices implementation of a 3D cube mesh.
   File   : CubeQ3.c
   Author : Afonso Santos, Portugal

   Last revision: 12h30 August 30 2016
*/

#include "Cube.h"
#include "MeshQ3.h"


MeshQ3*
CubeQ3_new
( )
{
  return MeshQ3_new( CUBE_VERTEXINFO.pointsNum   // # of vertices
                   , CUBE_EDGEINFO.edgesNum      // # of edges
                   , 6                           // # of faces
                   ) ;
}


void
CubeQ3_config
( MeshQ3    *this          // Cube mesh being configured.
, const Q    size
, Blinker   *inkBlinker
)
{
  if (this == NULL)
    return ;

  this->inkBlinker = inkBlinker ;

  MeshQ3_setFromI3XSTemplate( this
                            , &CUBE_VERTEXINFO
                            , &CUBE_EDGEINFO
                            , (Q3){ .x = size, .y = size, .z = size }
                            , Q3_origin                                 // Position
                            ) ;

  // Set faces.
  this->faces[0].faceInfo = &CUBE_FACE0 ;
  this->faces[1].faceInfo = &CUBE_FACE1 ;
  this->faces[2].faceInfo = &CUBE_FACE2 ;
  this->faces[3].faceInfo = &CUBE_FACE3 ;
  this->faces[4].faceInfo = &CUBE_FACE4 ;
  this->faces[5].faceInfo = &CUBE_FACE5 ;

  MeshQ3_calculateFaceNormals( this ) ;
}