/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_rotX.c
   Author : Afonso Santos, Portugal

   Last revision: 22h22 September 16 2016
*/

#include "Q3.h"


Q3*
Q3_rotX
(       Q3       *a
, const Q3       *b
, const int32_t   angle    // Pebble angle units
)
{
  const Q sin = sin_lookup( angle ) ;
  const Q cos = cos_lookup( angle ) ;

  const Q y = Q_mul( b->y, cos ) - Q_mul( b->z, sin ) ;
  const Q z = Q_mul( b->y, sin ) + Q_mul( b->z, cos ) ;

  a->x = b->x ;
  a->y = y ;
  a->z = z ;

  return a ;  
}