/*
   Package: FastMath
   File   : FastMath_reduceAngleRad.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 14h35 September 02 2016
*/

#include "FastMath.h"


inline
float
FastMath_reduceAngle
( float angleRad )
{
  angleRad = FastMath_normalizeAngleRad( angleRad ) ;

  if (angleRad > PI_DIV_2)
    angleRad -= PI ;

  if (angleRad < -PI_DIV_2)
    angleRad += PI ;

  return angleRad ;
}