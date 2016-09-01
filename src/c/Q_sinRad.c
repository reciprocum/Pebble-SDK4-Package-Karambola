/*
   Package    : Q - Fixed point (Q15.16) math. (adapted from libfixmath)
   File       : Q_sinRad.c
   Description: Trigonometric sin( ) function with angle parameter expressed in radian units.
   Author     : Afonso Santos, Portugal

   Last revision: 16h45 September 01 2016
*/

#include "Q.h"


inline
Q
Q_sinRad
( const Q angleRad )
{
  return Q_sinRad_( Q_reduceAngleRad( angleRad ) ) ;
}