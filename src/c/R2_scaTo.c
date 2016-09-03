/*
   Package: R2 - float based 2D algebra.
   File   : R2_scaTo.c
   Author : Afonso Santos, Portugal

   Last revision: 10h05 September 02 2016
*/

#include "R2.h"


//  s := k / |v| * v

R2*
R2_scaTo
( R2          *s
, const float  k
, const R2    *v
)
{
  const float modulus = R2_mod( v ) ;       // modulus = |v|

  if (modulus == 0.0f)
    return R2_assign( s, v ) ;

  return R2_sca( s, k / modulus, v ) ;
}