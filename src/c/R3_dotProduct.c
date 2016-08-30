/*
   Package: R3 - float based 3D algebra.
   File   : R3_dotProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


// a . b

float
R3_dotProduct
( const R3 *a
, const R3 *b
)
{
  return a->x * b->x
       + a->y * b->y
       + a->z * b->z
  ;
}