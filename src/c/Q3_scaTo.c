/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_scaTo.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 September 14 2016
*/

#include "Q3.h"


//  s := k / |v| * v

Q3*
Q3_scaTo
( Q3       *s
, const Q   k
, const Q3 *v
)
{
  const Q modulus = Q3_mod( v ) ;       // modulus = |v|

  if (modulus == Q_0)
    *s = *v ;
  else
    Q3_sca( s, Q_div( k, modulus ), v ) ;

  return s ;
}