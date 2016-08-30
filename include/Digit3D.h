/*
   Package: Digit3D
   File   : Digit3D.h
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 30 2016
*/

#pragma once

#include "Digit2D.h"
#include "MeshR3.h"


typedef struct
{ MeshR3       *mesh ;
  Digit2D_Type  type, typeMax ;
  int8_t        value ;          // Initialized with -1
} Digit3D ;


Digit3D*  Digit3D_free            ( Digit3D *this ) ;
void      Digit3D_setNull         ( Digit3D *this ) ;
Digit3D*  Digit3D_new             ( Digit2D_Type typeMax ) ;
void      Digit3D_setValue        ( Digit3D *this, const uint8_t value ) ;

void
Digit3D_config
( Digit3D      *this          // The Digit3D being configured.
, Digit2D_Type  type          // Display type can be changed on-the-fly.
, const R2      size          // width & heigth.
, const R2      anchor2D      // 2D translation of the 7 segment display.
, const R3      rotation3D    // 3D rotation of the 7 segment display.
, const R3      anchor3D      // 3D anchor of the segment display.
) ;