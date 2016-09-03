/*
   Package: R3 - float based 3D algebra.
   File   : R3_cross.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "R3.h"


// c := a x b

R3*
R3_cross
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