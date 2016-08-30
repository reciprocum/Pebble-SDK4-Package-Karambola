/*
   Package: R2 - float based 2D algebra.
   File   : R2_modulus.c
   Author : Afonso Santos, Portugal

   Last revision: 17h15 August 19 2016
*/

#include "FastMath.h"
#include "R2.h"


// |v|

float
R2_modulus
( const R2 *v )
{
  const float x = v->x ;
  const float y = v->y ;

  return FastMath_sqrt( x*x + y*y ) ;
}