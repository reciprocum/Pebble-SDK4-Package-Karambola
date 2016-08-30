/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3.h
   Author : Afonso Santos, Portugal

   Last revision: 16h05 August 30 2016
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


// v := { x, y, z }
Q3*    Q3_set( Q3 *v, const Q x, const Q y, const Q z ) ;

// b := a
Q3*    Q3_assign( Q3 *b, const Q3 *a ) ;

// a == b
bool   Q3_isEqual( const Q3 *a, const Q3 *b ) ;

// |v|
Q  Q3_modulus( const Q3 *v ) ;

// c := a + b
Q3*    Q3_add( Q3 *c, const Q3 *a, const Q3 *b ) ;

// c := a - b
Q3*    Q3_sub( Q3 *c, const Q3 *a, const Q3 *b ) ;

// b := k * a
Q3*    Q3_scalarProduct( Q3 *b, const Q	k, const Q3 *a ) ;

//  v := k / |v| * v
Q3*    Q3_scale( const Q k, Q3 *v ) ;

//  v := v / |v|
Q3*    Q3_versor( Q3 *v ) ;

// a . b
Q  Q3_dotProduct( const Q3 *a, const Q3 *b ) ;

// c := a x b
Q3*    Q3_crossProduct( Q3 *c, const Q3 *a, const Q3 *b ) ;