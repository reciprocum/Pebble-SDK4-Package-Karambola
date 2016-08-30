/*
   Package: CubeQ3 - Q15.16 based vertices implementation of a 3D cube mesh.
   File   : CubeQ3.h
   Author : Afonso Santos, Portugal

   Last revision: 12h25 August 30 2016
*/

#include "MeshQ3.h"


MeshQ3* CubeQ3_new( ) ;

void
CubeQ3_config
( MeshQ3  *this          // Cube mesh being configured.
, const Q  size
, Blinker *inkBlinker
) ;