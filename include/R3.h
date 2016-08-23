/*
   Package: R3
   File   : R3.h
   Author : Afonso Santos, Portugal

   Last revision: 17h05 August 16 2016
*/

#pragma once

#include <pebble.h>


typedef struct
{
  float x ;
  float y ;
  float z ;
} R3 ;


#define R3_origin        (R3){ .x = 0.0f, .y = 0.0f, .z = 0.0f }
#define R3_versorPlusX   (R3){ .x =+1.0f, .y = 0.0f, .z = 0.0f }
#define R3_versorMinusX  (R3){ .x =-1.0f, .y = 0.0f, .z = 0.0f }
#define R3_versorPlusY   (R3){ .x = 0.0f, .y =+1.0f, .z = 0.0f }
#define R3_versorMinusY  (R3){ .x = 0.0f, .y =-1.0f, .z = 0.0f }
#define R3_versorPlusZ   (R3){ .x = 0.0f, .y = 0.0f, .z =+1.0f }
#define R3_versorMinusZ  (R3){ .x = 0.0f, .y = 0.0f, .z =-1.0f }


// v := { x, y, z }
R3*    R3_set( R3 *v, const float x, const float y, const float z ) ;

// b := a
R3*    R3_assign( R3 *b, const R3 *a ) ;

// a == b
bool   R3_isEqual( const R3 *a, const R3 *b ) ;

// |v|
float  R3_modulus( const R3 *v ) ;

// c := a + b
R3*    R3_add( R3 *c, const R3 *a, const R3 *b ) ;

// c := a - b
R3*    R3_sub( R3 *c, const R3 *a, const R3 *b ) ;

// b := k * a
R3*    R3_scalarProduct( R3 *b, const float	k, const R3 *a ) ;

//  v := k / |v| * v
R3*    R3_scale( const float k, R3 *v ) ;

//  v := v / |v|
R3*    R3_versor( R3 *v ) ;

// a . b
float  R3_dotProduct( const R3 *a, const R3 *b ) ;

// c := a x b
R3*    R3_crossProduct( R3 *c, const R3 *a, const R3 *b ) ;