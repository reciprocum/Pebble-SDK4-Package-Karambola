/*
   Package: I3
   File   : I3.h
   Author : Afonso Santos, Portugal

   Last revision: 11h20 August 23 2016
*/

#pragma once

#include <pebble.h>


// I3 - eXtra Small (1 byte only coords, max 256 points)

#define I3XS_MAXABS  120


typedef struct
{ int8_t x ;
  int8_t y ;
  int8_t z ;
} I3XS ;


typedef struct
{ uint8_t   pointsNum ;
  I3XS     *points ;
} I3XS_PointInfo ;


// I3 - Small (2 byte coords, max 65K points)

#define I3S_MAXABS  32000


typedef struct
{ int16_t x ;
  int16_t y ;
  int16_t z ;
} I3S ;


typedef struct
{ uint16_t pointsNum ;
  I3S     *points ;
} I3S_PointInfo ;


// I3 (full integer coords, max 2G points)

#define I3_MAXABS  1000000000


typedef struct
{ int x ;
  int y ;
  int z ;
} I3 ;


typedef struct
{ unsigned int pointsNum ;
  I3          *points ;
} I3_PointInfo ;