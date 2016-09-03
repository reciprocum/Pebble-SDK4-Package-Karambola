/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_scaTo.c
   Author : Afonso Santos, Portugal

   Last revision: 06h15 September 02 2016
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
    return Q2_assign( s, v ) ;

  return Q2_sca( s, Q_div( k, modulus ), v ) ;
}