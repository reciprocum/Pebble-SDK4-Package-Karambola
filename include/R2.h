/*
   Package: R2 - float based 2D algebra.
   File   : R2.h
   Author : Afonso Santos, Portugal

   Last revision: 12h25 September 14 2016
*/

#pragma once

#include <pebble.h>


typedef struct
{
  float x ;
  float y ;
} R2 ;


extern const R2 R2_origin        ;
extern const R2 R2_versorPlusX   ;
extern const R2 R2_versorMinusX  ;
extern const R2 R2_versorPlusY   ;
extern const R2 R2_versorMinusY  ;


//  v := { x, y }
R2*   R2_set( R2 *v, const float x, const float y ) ;

//  a == b
bool  R2_isEqual( const R2 *a, const R2 *b ) ;

//  |v|
float R2_mod( const R2 *v ) ;

//  c := a + b
R2*   R2_add( R2 *c, const R2 *a, const R2 *b ) ;

//  c := a - b
R2*   R2_sub( R2 *c, const R2 *a, const R2 *b ) ;

//  b := k * a
R2*   R2_sca( R2 *b, const float k, const R2 *a ) ;

//  b := k / |a| * a
R2*   R2_scaTo( R2 *b, const float k, const R2 *a ) ;

//  b = a / |a|
R2*   R2_versor( R2 *b, const R2 *a ) ;

//  a . b
float R2_dot( const R2 *a, const R2 *b ) ;

//  a := b X ROT( angleRad )
R2*   R2_rotRad( R2 *a, const R2 *b, const float  angleRad ) ;
