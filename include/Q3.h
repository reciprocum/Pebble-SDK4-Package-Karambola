/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3.h
   Author : Afonso Santos, Portugal

   Last revision: 23h55 September 02 2016
*/

#pragma once

#include "Q.h"


typedef struct
{
  Q x ;
  Q y ;
  Q z ;
} Q3 ;


extern const Q3 Q3_origin       ;
extern const Q3 Q3_versorPlusX  ;
extern const Q3 Q3_versorMinusX ;
extern const Q3 Q3_versorPlusY  ;
extern const Q3 Q3_versorMinusY ;
extern const Q3 Q3_versorPlusZ  ;
extern const Q3 Q3_versorMinusZ ;


//  v := { x, y, z }
Q3*    Q3_set( Q3 *v, const Q x, const Q y, const Q z ) ;

//  b := a
Q3*    Q3_assign( Q3 *b, const Q3 *a ) ;

//  a == b
bool   Q3_isEqual( const Q3 *a, const Q3 *b ) ;

//  |v|
Q      Q3_mod( const Q3 *v ) ;

//  c := a + b
Q3*    Q3_add( Q3 *c, const Q3 *a, const Q3 *b ) ;

//  c := a - b
Q3*    Q3_sub( Q3 *c, const Q3 *a, const Q3 *b ) ;

//  s := k * v
Q3*    Q3_sca( Q3 *s, const Q	k, const Q3 *v ) ;

//  s := k / |v| * v
Q3*    Q3_scaTo( Q3 *s, const Q k, const Q3 *v ) ;

//  a = b / |b|
Q3*    Q3_versor( Q3 *a, const Q3 *b ) ;

//  a . b
Q      Q3_dot( const Q3 *a, const Q3 *b ) ;

//  c := a x b
Q3*    Q3_cross( Q3 *c, const Q3 *a, const Q3 *b ) ;

//  a := b X ROTZ( angle )
Q3*    Q3_rotZ( Q3 *a, const Q3 *b, const int32_t agle ) ;

//  a := b X ROTZ( angleRad )
Q3*    Q3_rotZrad( Q3 *a, const Q3 *b, const Q agleRad ) ;
