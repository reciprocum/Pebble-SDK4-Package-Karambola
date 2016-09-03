/*
   Package: FastMath
   File   : FastMath_sinRad.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 14h35 September 02 2016
*/

#include "FastMath.h"


/* Avoid: benchmarked to be 10x slower than pebble's native sin_lookup( ) */
float
FastMath_sinRad
( float x )
{
  float sin ;

  if (x < -PI)
    x += PI_MUL_2 ;

  if (x > PI)
    x -= PI_MUL_2 ;

  if (x < 0)
  {
    sin = 1.2732395f * x + 0.40528473f * x * x ;

    if (sin < 0)
      sin = 0.225f * (sin *-sin - sin) + sin ;
    else
      sin = 0.225f * (sin * sin - sin) + sin ;
  }
  else
  {
    sin = 1.2732395f * x - 0.40528473f * x * x ;

    if (sin < 0)
      sin = 0.225f * (sin *-sin - sin) + sin ;
    else
      sin = 0.225f * (sin * sin - sin) + sin ;
  }

  return sin ;
}
