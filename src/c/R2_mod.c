/*
   Package: R2 - float based 2D algebra.
   File   : R2_mod.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "FastMath.h"
#include "R2.h"


// |v|

float
R2_mod
( const R2 *v )
{
  const float x = v->x ;
  const float y = v->y ;

  return FastMath_sqrt( x*x + y*y ) ;
}