/*
   Package: R2 - float based 2D algebra.
   File   : R2_scaTo.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 September 14 2016
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
    *s = *v ;
  else
    R2_sca( s, k / modulus, v ) ;

  return s ;
}