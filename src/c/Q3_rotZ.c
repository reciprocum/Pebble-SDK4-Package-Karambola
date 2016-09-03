/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_rotZ.c
   Author : Afonso Santos, Portugal

   Last revision: 00h00 September 03 2016
*/

#include "Q3.h"


Q3*
Q3_rotZ
(       Q3       *a
, const Q3       *b
, const int32_t   angle    // Pebble angle units
)
{
  const Q sin = sin_lookup( angle ) ;
  const Q cos = cos_lookup( angle ) ;

  const Q x = Q_mul( b->x, cos ) - Q_mul( b->y, sin ) ;
  const Q y = Q_mul( b->x, sin ) + Q_mul( b->y, cos ) ;

  a->x = x ;
  a->y = y ;
  a->z = b->z ;

  return a ;  
}