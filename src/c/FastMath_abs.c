/*
   Package: FastMath
   File   : FastMath_abs.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 13h45 August 22 2016
*/


float
FastMath_abs
( const float f )
{ return (f < 0.0) ? -f : f ; }