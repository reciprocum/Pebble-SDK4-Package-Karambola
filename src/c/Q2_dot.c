/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_dot.c
   Author : Afonso Santos, Portugal

   Last revision: 06h15 September 02 2016
*/

#include "Q2.h"


// a . b

Q
Q2_dot
( const Q2 *a
, const Q2 *b
)
{
  return Q_mul( a->x, b->x ) + Q_mul( a->y, b->y ) ;           // a->x * b->x  +  a->y * b->y
}