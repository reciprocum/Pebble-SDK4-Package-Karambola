/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_scale.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


//  v := k / |v| * v

Q2*
Q2_scale
( const Q  k
, Q2      *v
)
{
  const Q modulus = Q2_modulus( v ) ;       // modulus = |v|
  const Q scale   = Q_div( k, modulus ) ;   // scale   = k / |v|

  return Q2_scalarProduct( v, scale, v ) ;
}