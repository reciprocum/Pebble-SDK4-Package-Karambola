/*
   Package: R2 - float based 2D algebra.
   File   : R2_scale.c
   Author : Afonso Santos, Portugal

   Last revision: 17h50 August 19 2016
*/

#include "R2.h"


//  v := k / |v| * v

R2*
R2_scale
( const float  k
, R2          *v
)
{
  const float modulus = R2_modulus( v ) ;
  
  if (modulus == 0.0f)
    return v ;

  return R2_scalarProduct( v, k / modulus, v ) ;
}