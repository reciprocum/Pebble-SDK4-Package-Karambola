/*
   Package: R3 - float based 3D algebra.
   File   : R3_scaTo.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 September 14 2016
*/

#include "R3.h"


//  s := k / |v| * v

R3*
R3_scaTo
( R3          *s
, const float  k
, const R3    *v
)
{
  const float mod_v = R3_mod( v ) ;       // mod_v = |v|

  if (mod_v == 0.0f)
    *s = *v ;
  else
    R3_sca( s, k / mod_v, v ) ;
  
  return s ;
}