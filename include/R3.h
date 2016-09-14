/*
   Package: R3 - float based 3D algebra.
   File   : R3.h
   Author : Afonso Santos, Portugal

   Last revision: 12h25 September 14 2016
*/

#pragma once

#include <pebble.h>


typedef struct
{
  float x ;
  float y ;
  float z ;
} R3 ;


extern const R3 R3_origin        ;
extern const R3 R3_versorPlusX   ;
extern const R3 R3_versorMinusX  ;
extern const R3 R3_versorPlusY   ;
extern const R3 R3_versorMinusY  ;
extern const R3 R3_versorPlusZ   ;
extern const R3 R3_versorMinusZ  ;


//  v := { x, y, z }
R3*    R3_set( R3 *v, const float x, const float y, const float z ) ;

//  a == b
bool   R3_isEqual( const R3 *a, const R3 *b ) ;

//  |v|
float  R3_mod( const R3 *v ) ;

//  c := a + b
R3*    R3_add( R3 *c, const R3 *a, const R3 *b ) ;

//  c := a - b
R3*    R3_sub( R3 *c, const R3 *a, const R3 *b ) ;

//  b := k * a
R3*    R3_sca( R3 *b, const float	k, const R3 *a ) ;

//  b := k / |a| * a
R3*    R3_scaTo( R3 *b, const float k, const R3 *a ) ;

//  b = a / |a|
R3*    R3_versor( R3 *b, const R3 *a ) ;

//  a . b
float  R3_dot( const R3 *a, const R3 *b ) ;

//  c := a x b
R3*    R3_cross( R3 *c, const R3 *a, const R3 *b ) ;

//  a := b X ROTZ( angleRad )
R3*    R3_rotZrad( R3 *a, const R3 *b, const float  angleRad ) ;
