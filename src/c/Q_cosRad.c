/*
   Package    : Q - Fixed point (Q15.16) math. (adapted from libfixmath)
   File       : Q_cosRad.c
   Description: Trigonometric cos( ) function with angle parameter expressed in radian units.
   Author     : Afonso Santos, Portugal

   Last revision: 16h45 September 01 2016
*/

#include "Q.h"


inline
Q
Q_cosRad
( const Q angleRad )
{
	return Q_sinRad( angleRad + Q_PI_DIV_2 ) ;
}