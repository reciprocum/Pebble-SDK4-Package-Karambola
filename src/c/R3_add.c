/*
   Package: R3 - float based 3D algebra.
   File   : R3_add.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


// c := a + b

R3*
R3_add
( R3       *c
, const R3 *a
, const R3 *b
)
{
  c->x = a->x + b->x ;
  c->y = a->y + b->y ;
  c->z = a->z + b->z ;

  return c ;
}