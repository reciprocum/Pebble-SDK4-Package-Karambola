/*
   Package: Cube
   File   : Cube.h
   Author : Afonso Santos, Portugal

   Last revision: 12h30 August 23 2016
*/

#include "Mesh3D.h"


Mesh3D* Cube_new( ) ;

void
Cube_config
( Mesh3D      *this          // Cube mesh being configured.
, const float  size
, Blinker     *inkBlinker
) ;