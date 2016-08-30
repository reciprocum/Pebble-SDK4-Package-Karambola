/*
   Package: R2 - float based 2D algebra.
   File   : R2_scalarProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 17h45 August 19 2016
*/

#include "R2.h"


// b := k * a

R2*
R2_scalarProduct
( R2         *b
, const float	k
, const R2   *a
)
{
  b->x = k * a->x ;
  b->y = k * a->y ;
 
  return b ;
}