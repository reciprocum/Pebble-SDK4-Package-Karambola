/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_scalarProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


// b := k * a

Q2*
Q2_scalarProduct
( Q2       *b
, const Q	  k
, const Q2 *a
)
{
  b->x = Q_mul( k, a->x ) ;   // b->x = k * a->x
  b->y = Q_mul( k, a->y ) ;   // b->y = k * a->y
 
  return b ;
}