/*
   package: I2
   File   : I2_8.h   - eXtra Small (8 bit coords, max 256 points)
   Author : Afonso Santos, Portugal

   Last revision: 11h20 August 23 2016
*/

#pragma once

#include <pebble.h>

#define I2_8_MAXABS  120


typedef struct
{ int8_t x ;
  int8_t y ;
} I2_8 ;


typedef struct
{ uint8_t   pointsNum ;
  I2_8     *points ;
} I2_8_PathInfo ;