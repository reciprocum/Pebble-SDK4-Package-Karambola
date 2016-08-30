/*
   Package: Q - Fixed point (Q15.16) math.
   File   : Q_normalizeAngle.c
   Author : Afonso Santos, Portugal

   Last revision: 11h05 August 29 2016
*/

#include "Q.h"


Q
Q_normalizeAngle
( Q a )
{
  while (a < -Q_PI)
    a += Q_2PI ;

  while (a > Q_PI)
    a -= Q_2PI ;

  return a ;
}