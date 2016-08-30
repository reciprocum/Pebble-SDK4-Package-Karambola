/*
   Package: R3 - float based 3D algebra.
   File   : R3_crossProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


// c := a x b

R3*
R3_crossProduct
( R3       *c
, const R3 *a
, const R3 *b
)
{
  c->x = a->y * b->z - a->z * b->y ;
  c->y = a->z * b->x - a->x * b->z ;
  c->z = a->x * b->y - a->y * b->x ;

  return c ;
}