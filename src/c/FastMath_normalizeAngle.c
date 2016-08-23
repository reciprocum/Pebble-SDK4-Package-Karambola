/*
   Package: FastMath
   File   : FastMath_normalizeAngle.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 13h45 August 22 2016
*/

#include "FastMath.h"


float
FastMath_normalizeAngle
( float a )
{
  while (a < -PI_1)
    a += PI_2 ;

  while (a > PI_1)
    a -= PI_2 ;

  return a ;
}