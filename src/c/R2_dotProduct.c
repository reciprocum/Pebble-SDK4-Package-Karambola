/*
   Package: R2 - float based 2D algebra.
   File   : R2_dotProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 17h50 August 19 2016
*/

#include "R2.h"


// a . b

float
R2_dotProduct
( const R2 *a
, const R2 *b
)
{
  return a->x * b->x
       + a->y * b->y
  ;
}