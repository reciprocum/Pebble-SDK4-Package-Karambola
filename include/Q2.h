/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2.h
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#pragma once

#include "Q.h"


typedef struct
{
  Q x ;
  Q y ;
} Q2 ;


#define Q2_origin        (Q2){ .x = Q_0, .y = Q_0 }
#define Q2_versorPlusX   (Q2){ .x =+Q_1, .y = Q_0 }
#define Q2_versorMinusX  (Q2){ .x =-Q_1, .y = Q_0 }
#define Q2_versorPlusY   (Q2){ .x = Q_0, .y =+Q_1 }
#define Q2_versorMinusY  (Q2){ .x = Q_0, .y =-Q_1 }


// v := { x, y }
Q2*   Q2_set( Q2 *v, const Q x, const Q y ) ;

// b := a
Q2*   Q2_assign( Q2 *b, const Q2 *a ) ;

// a == b
bool  Q2_isEqual( const Q2 *a, const Q2 *b ) ;

Q Q2_modulus( const Q2 *v ) ;

// c := a + b
Q2*   Q2_add( Q2 *c, const Q2 *a, const Q2 *b ) ;

// c := a - b
Q2*   Q2_sub( Q2 *c, const Q2 *a, const Q2 *b ) ;

// b := k * a
Q2*   Q2_scalarProduct( Q2 *b, const Q k, const Q2 *a ) ;

//  v := k / |v| * v
Q2*   Q2_scale( const Q k, Q2 *v ) ;

//  v := v / |v|
Q2*   Q2_versor( Q2 *v ) ;

// a . b
Q Q2_dotProduct( const Q2 *a, const Q2 *b ) ;