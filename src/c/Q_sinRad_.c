/*
   Package    : Q - Fixed point (Q15.16) math. (adapted from libfixmath)
   File       : Q_sinRad_.c
   Description: Trigonometric sin( ) function with angle parameter expressed in radian units.
              : No parameter angle reduction/normalization is performed.
   CAUTION !! : Works only for <angleRad> parameter values in the range [-PI/2, +PI/2]
   Author     : Afonso Santos, Portugal

   Last revision: 16h45 September 01 2016
*/

#include "Q.h"


Q
Q_sinRad_
( const Q angleRad )
{
  const Q angle2 = Q_mul( angleRad, angleRad ) ;

  Q result ;
  result = Q_mul( -13   , angle2  ) + 546 ;
  result = Q_mul( result, angle2  ) - 10923 ;
  result = Q_mul( result, angle2  ) + 65536 ;
  result = Q_mul( result, angleRad ) ;

  return result ;
}