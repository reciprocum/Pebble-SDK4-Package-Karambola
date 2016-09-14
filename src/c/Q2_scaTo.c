/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_scaTo.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 September 14 2016
*/

#include "Q2.h"


//  s := k / |v| * v

Q2*
Q2_scaTo
( Q2       *s
, const Q   k
, const Q2 *v
)
{
  const Q modulus = Q2_mod( v ) ;       // modulus = |v|

  if (modulus == Q_0)
    *s = *v ;
  else
    Q2_sca( s, Q_div( k, modulus ), v ) ;
  
  return s ;
}