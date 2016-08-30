/*
   Package: R3 - float based 3D algebra.
   File   : R3_scale.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


//  v := k / |v| * v

R3*
R3_scale
( const float  k
, R3          *v
)
{
  const float scale = k / R3_modulus( v ) ;

  return R3_scalarProduct( v, scale, v ) ;
}