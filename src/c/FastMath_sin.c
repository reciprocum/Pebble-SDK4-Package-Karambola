/*
   Package: FastMath
   File   : FastMath_sin.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 13h45 August 22 2016
*/

#include "FastMath.h"


float
FastMath_sin
( float x )
{
  float sin ;

  if (x < -PI_1)
    x += PI_2 ;

  if (x > PI_1)
    x -= PI_2 ;

  if (x < 0)
  {
    sin = 1.2732395 * x + .40528473 * x * x ;

    if (sin < 0)
      sin = .225 * (sin *-sin - sin) + sin ;
    else
      sin = .225 * (sin * sin - sin) + sin ;
  } else
  {
    sin = 1.2732395 * x - .40528473 * x * x ;

    if (sin < 0)
      sin = .225 * (sin *-sin - sin) + sin ;
    else
      sin = .225 * (sin * sin - sin) + sin ;
  }

  return sin ;
}