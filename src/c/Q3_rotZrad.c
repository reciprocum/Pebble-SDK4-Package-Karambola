/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_rotZrad.c
   Author : Afonso Santos, Portugal

   Last revision: 15h28 September 02 2016
*/

#include "Q3.h"


Q3*
Q3_rotZrad
(       Q3 *a
, const Q3 *b
, const Q   angleRad
)
{
  const Q sin = Q_sinRad( angleRad ) ;
  const Q cos = Q_cosRad( angleRad ) ;

  const Q x = Q_mul( b->x, cos ) - Q_mul( b->y, sin ) ;
  const Q y = Q_mul( b->x, sin ) + Q_mul( b->y, cos ) ;

  a->x = x ;
  a->y = y ;
  a->z = b->z ;

  return a ;  
}