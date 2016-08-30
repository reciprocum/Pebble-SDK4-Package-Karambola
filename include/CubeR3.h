/*
   Package: CubeR3 - float based vertices implementation of a 3D cube mesh.
   File   : CubeR3.h
   Author : Afonso Santos, Portugal

   Last revision: 19h55 August 29 2016
*/

#include "MeshR3.h"


MeshR3* CubeR3_new( ) ;

void
CubeR3_config
( MeshR3      *this          // Cube mesh being configured.
, const float  size
, Blinker     *inkBlinker
) ;