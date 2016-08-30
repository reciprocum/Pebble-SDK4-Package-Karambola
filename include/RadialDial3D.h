/*
   Package: RadialDial3D
   File   : RadialDial3D.h
   Author : Afonso Santos, Portugal

   Last revision: 10h45 August 30 2016
*/

#pragma once

#include "MeshR3.h"
#include "RadialDial2D.h"


typedef struct
{ MeshR3        *mesh ;
  RadialDialType type ;
  int8_t         value ;          // Initialized with -1
} RadialDial3D ;


RadialDial3D*  RadialDial3D_new ( RadialDialType type ) ;
RadialDial3D*  RadialDial3D_free( RadialDial3D *this ) ;

void
RadialDial3D_config
( RadialDial3D          *this               // MUST already contain/point a/to pre-allocated mesh.
, const RadialDialShape  shape
, const float            innerRadius
, const float            outerRadius
, const R3               rotation
, const R3               translation        // Center of the radial handle
) ;

void  RadialDial3D_setNull ( RadialDial3D *this ) ;
void  RadialDial3D_setValue( RadialDial3D *this, const uint8_t value ) ;