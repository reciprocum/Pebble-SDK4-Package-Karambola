/*
   Package: FastMath
   File   : FastMath_reduceAngle.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 13h45 August 22 2016
*/

#include "FastMath.h"


float
FastMath_reduceAngle
( float a )
{
  a = FastMath_normalizeAngle( a ) ;

  if (a < -PI_HALF)
    a += PI_1 ;

  if (a > PI_HALF)
    a -= PI_1 ;

  return a ;
}