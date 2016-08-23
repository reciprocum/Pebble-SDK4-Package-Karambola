/*
   Package: FastMath
   File   : FastMath_sqrt.c
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 13h45 August 22 2016
*/


// See http://en.wikipedia.org/wiki/Fast_inverse_square_root for more details;
// In our last step we multiply with 'x' in order to make '1/sqrt(x)' to 'sqrt(x)'.

#define SQRT_MAGIC_F 0x5f3759df 

float
FastMath_sqrt
( const float x )
{
  union
  { float x ;
    int   i ;
  } u ;

  u.x = x ;
  u.i = SQRT_MAGIC_F - (u.i >> 1) ;

  // newton step for increased accuracy
  return x * u.x * (1.5f - 0.5f * x * u.x * u.x) ;
}