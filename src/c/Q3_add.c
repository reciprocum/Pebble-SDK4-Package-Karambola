/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_add.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


// c := a + b

Q3*
Q3_add
( Q3       *c
, const Q3 *a
, const Q3 *b
)
{
  c->x = a->x + b->x ;
  c->y = a->y + b->y ;
  c->z = a->z + b->z ;

  return c ;
}