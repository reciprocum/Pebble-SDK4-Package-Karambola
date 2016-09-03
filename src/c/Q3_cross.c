/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_cross.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "Q3.h"


// c := a x b

Q3*
Q3_cross
( Q3       *c
, const Q3 *a
, const Q3 *b
)
{
  c->x = Q_mul( a->y, b->z ) - Q_mul( a->z, b->y ) ;
  c->y = Q_mul( a->z, b->x ) - Q_mul( a->x, b->z ) ;
  c->z = Q_mul( a->x, b->y ) - Q_mul( a->y, b->x ) ;

  return c ;
}