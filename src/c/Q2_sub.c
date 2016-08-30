/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_sub.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


// c := a - b

Q2*
Q2_sub
( Q2       *c
, const Q2 *a
, const Q2 *b
)
{
  c->x = a->x - b->x ;
  c->y = a->y - b->y ;
 
  return c ;
}