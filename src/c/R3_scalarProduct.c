/*
   Package: R3 - float based 3D algebra.
   File   : R3_scalarProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


// b := k * a

R3*
R3_scalarProduct
( R3         *b
, const float	k
, const R3   *a
)
{
  b->x = k * a->x ;
  b->y = k * a->y ;
  b->z = k * a->z ;

  return b ;
}