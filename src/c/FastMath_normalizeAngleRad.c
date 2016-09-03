/*
   Package: FastMath
   File   : FastMath_normalizeAngleRad.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 14h35 September 02 2016
*/

#include "FastMath.h"


inline
float
FastMath_normalizeAngleRad
( float angleRad )
{
  while (angleRad < -PI)
    angleRad += PI_MUL_2 ;

  while (angleRad > PI)
    angleRad -= PI_MUL_2 ;

  return angleRad ;
}