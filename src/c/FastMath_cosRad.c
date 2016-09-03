/*
   Package: FastMath
   File   : FastMath_cosRad.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 14h35 September 02 2016
*/

#include "FastMath.h"


/* Avoid: benchmarked to be 10x slower than pebble's native cos_lookup( ) */
inline
float
FastMath_cosRad
( const float x )
{ return FastMath_sinRad( x + PI_DIV_2 ) ; }
