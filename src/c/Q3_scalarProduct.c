/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_scalarProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


// b := k * a

Q3*
Q3_scalarProduct
( Q3       *b
, const Q	  k
, const Q3 *a
)
{
  b->x = Q_mul( k, a->x ) ;
  b->y = Q_mul( k, a->y ) ;
  b->z = Q_mul( k, a->z ) ;

  return b ;
}