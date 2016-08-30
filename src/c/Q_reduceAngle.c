/*
   Package: Q - Fixed point (Q15.16) math.
   File   : Q_reduceAngle.c
   Author : Afonso Santos, Portugal

   Last revision: 11h05 August 29 2016
*/

#include "Q.h"


Q
Q_reduceAngle
( Q a )
{
  a = Q_normalizeAngle( a ) ;

  if (a < -Q_PI2)
    a += Q_PI ;

  if (a > Q_PI2)
    a -= Q_PI ;

  return a ;
}