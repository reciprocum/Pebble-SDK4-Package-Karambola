/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_scale.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


//  v := k / |v| * v

Q3*
Q3_scale
( const Q  k
, Q3      *v
)
{
  const Q modulus = Q3_modulus( v ) ;      // modulus = |v|

  if (modulus == Q_0)
    return v ;

  const Q scale = Q_div( k, modulus ) ;     // scale   = k / |v|

  return Q3_scalarProduct( v, scale, v ) ;  // k / |v| * v
}