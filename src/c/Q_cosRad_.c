/*
   Package    : Q - Fixed point (Q15.16) math. (adapted from libfixmath)
   File       : Q_cosRad_.c
   Description: Trigonometric cos( ) function with angle parameter expressed in radian units.
              : No parameter angle reduction/normalization is performed.
   CAUTION !! : Works only for <angleRad> parameter values in the range [PI, 0]
   Author     : Afonso Santos, Portugal

   Last revision: 16h45 September 01 2016
*/

#include "Q.h"


inline
Q
Q_cosRad_
( const Q angleRad )
{
	return Q_sinRad_( angleRad + Q_PI_DIV_2 ) ;
}