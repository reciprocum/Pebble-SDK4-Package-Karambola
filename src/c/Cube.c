/*
   Package: Cube
   File   : Cube.c
   Author : Afonso Santos, Portugal

   Last revision: 13h30 August 23 2016
*/

#include "Mesh3D.h"


static I3XS_PointInfo CUBE_VERTEXINFO
= { .pointsNum = 8
  , .points    = (I3XS[])
                 { {-120, 120, 120 }   // v0
                 , { 120, 120, 120 }   // v1
                 , { 120,-120, 120 }   // v2
                 , {-120,-120, 120 }   // v3
                 , {-120, 120,-120 }   // v4
                 , { 120, 120,-120 }   // v5
                 , { 120,-120,-120 }   // v6
                 , {-120,-120,-120 }   // v7
                 }
  }
;


static EdgeInfo CUBE_EDGEINFO
= { .edgesNum = 12
  , .edges    = (Edge[])
                { { 0, 1 }      // e0  = v0 v1
                , { 1, 2 }      // e1  = v1 v2
                , { 2, 3 }      // e2  = v2 v3
                , { 3, 0 }      // e3  = v3 v0
                , { 4, 5 }      // e4  = v4 v5
                , { 5, 6 }      // e5  = v5 v6
                , { 6, 7 }      // e6  = v6 v7
                , { 7, 4 }      // e7  = v7 v4
                , { 0, 4 }      // e8  = v0 v4
                , { 1, 5 }      // e9  = v1 v5
                , { 2, 6 }      // e10 = v2 v6
                , { 3, 7 }      // e11 = v3 v7
                }
  }
;


static FaceInfo CUBE_FACE0
= { .edgesNum    = 4
  , .edgeIndexes = (uint16_t[]){ 1, 0,  2, 3 }        // f0 = e1 e0 e2 e3
  }
;

static FaceInfo CUBE_FACE1
= { .edgesNum    = 4
  , .edgeIndexes = (uint16_t[]){ 4, 5,  6, 7 }        // f1 = e4 e5 e6 e7
  }
;

static FaceInfo CUBE_FACE2
= { .edgesNum    = 4
  , .edgeIndexes = (uint16_t[]){ 0, 8,  4, 9 }        // f2 = e0 e8 e4 e9
  }
;

static FaceInfo CUBE_FACE3
= { .edgesNum    = 4
  , .edgeIndexes = (uint16_t[]){ 5, 9, 10, 1 }        // f3 = e5 e9 e10 e1
  }
;

static FaceInfo CUBE_FACE4
= { .edgesNum    = 4
  , .edgeIndexes = (uint16_t[]){ 2,10, 11, 6 }        // f4 = e2 e10 e11 e6
  }
;

static FaceInfo CUBE_FACE5
= { .edgesNum    = 4
  , .edgeIndexes = (uint16_t[]){ 7,11,  3, 8 }        // f5 = e7 e11  e3 e8
  }
;


Mesh3D*
Cube_new
( )
{
  return Mesh3D_new( CUBE_VERTEXINFO.pointsNum   // # of vertices
                   , CUBE_EDGEINFO.edgesNum      // # of edges
                   , 6                           // # of faces
                   ) ;
}


void
Cube_config
( Mesh3D      *this          // Cube mesh being configured.
, const float  size
, Blinker     *inkBlinker
)
{
  if (this == NULL)
    return ;

  this->inkBlinker = inkBlinker ;

  Mesh3D_setFromI3XSTemplate( this
                            , &CUBE_VERTEXINFO
                            , &CUBE_EDGEINFO
                            , size
                            , 0            // rotationX
                            , 0            // rotationY
                            , 0            // rotationZ
                            , &R3_origin   // anchor3D
                            ) ;

  // Set faces.
  this->faces[0].faceInfo = &CUBE_FACE0 ;
  this->faces[1].faceInfo = &CUBE_FACE1 ;
  this->faces[2].faceInfo = &CUBE_FACE2 ;
  this->faces[3].faceInfo = &CUBE_FACE3 ;
  this->faces[4].faceInfo = &CUBE_FACE4 ;
  this->faces[5].faceInfo = &CUBE_FACE5 ;

  Mesh3D_calculateFaceNormals( this ) ;
}