/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_dotProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


// a . b

Q
Q2_dotProduct
( const Q2 *a
, const Q2 *b
)
{
  return Q_mul( a->x, b->x ) + Q_mul( a->y, b->y ) ;           // a->x * b->x  +  a->y * b->y
}