/*
   Package: FastMath
   File   : FastMath_cos.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 13h45 August 22 2016
*/

#include "FastMath.h"


float
FastMath_cos
( const float x )
{ return FastMath_sin( x + PI_HALF ) ; }