/*
   Package: R3 - float based 3D algebra.
   File   : R3_modulus.c
   Author : Afonso Santos, Portugal

   Last revision: 11h35 August 23 2016
*/

#include "FastMath.h"
#include "R3.h"


// |v|

float
R3_modulus
( const R3 *v )
{
  const float x = v->x ;
  const float y = v->y ;
  const float z = v->z ;

  return FastMath_sqrt( x*x + y*y + z*z ) ;
}