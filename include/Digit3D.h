/*
   Package: Digit3D
   File   : Digit3D.h
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 23 2016
*/

#pragma once

#include "Digit2D.h"
#include "Mesh3D.h"


typedef struct
{ Mesh3D       *mesh ;
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
, const float   width
, const float   height
, const float   shiftX
, const float   rotationX
, const float   rotationY
, const float   rotationZ
, const R3     *anchor3D      // 3D anchor of the 7 segment display.
) ;