/*
   Package: R2 - float based 2D algebra.
   File   : R2_dot.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "R2.h"


// a . b

float
R2_dot
( const R2 *a
, const R2 *b
)
{
  return a->x * b->x
       + a->y * b->y
  ;
}