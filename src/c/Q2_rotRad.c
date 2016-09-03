/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_rotRad.c
   Author : Afonso Santos, Portugal

   Last revision: 15h28 September 02 2016
*/

#include "Q2.h"


Q2*
Q2_rotRad
(       Q2 *a
, const Q2 *b
, const Q   angleRad
)
{
  const Q sin = Q_sinRad( angleRad ) ;
  const Q cos = Q_cosRad( angleRad ) ;

  const Q x = Q_mul( b->x, cos ) - Q_mul( b->y, sin ) ;
  const Q y = Q_mul( b->x, sin ) + Q_mul( b->y, cos ) ;

  a->x = x ;
  a->y = y ;

  return a ;  
}