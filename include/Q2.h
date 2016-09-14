/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2.h
   Author : Afonso Santos, Portugal

   Last revision: 12h25 September 14 2016
*/

#pragma once

#include "Q.h"


typedef struct
{
  Q x ;
  Q y ;
} Q2 ;


extern const Q2 Q2_origin       ;
extern const Q2 Q2_versorPlusX  ;
extern const Q2 Q2_versorMinusX ;
extern const Q2 Q2_versorPlusY  ;
extern const Q2 Q2_versorMinusY ;


//  v := { x, y }
Q2*   Q2_set( Q2 *v, const Q x, const Q y ) ;

//  a == b
bool  Q2_isEqual( const Q2 *a, const Q2 *b ) ;

//  |v|
Q     Q2_mod( const Q2 *v ) ;

//  c := a + b
Q2*   Q2_add( Q2 *c, const Q2 *a, const Q2 *b ) ;

//  c := a - b
Q2*   Q2_sub( Q2 *c, const Q2 *a, const Q2 *b ) ;

//  b := k * a
Q2*   Q2_sca( Q2 *b, const Q k, const Q2 *a ) ;

//  s := k / |v| * v
Q2*   Q2_scaTo( Q2 *s, const Q k, const Q2 *v ) ;

//  a = b / |b|
Q2*   Q2_versor( Q2 *a, const Q2 *b ) ;

//  a . b
Q     Q2_dot( const Q2 *a, const Q2 *b ) ;

//  a := b X ROT( angleRad )
Q2*   Q2_rotRad( Q2 *a, const Q2 *b, const Q agleRad ) ;
