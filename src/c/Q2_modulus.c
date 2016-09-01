/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_modulus.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


// |v|

Q
Q2_modulus
( const Q2 *v )
{
  const Q x = v->x ;
  const Q y = v->y ;

  return Q_sqrt( Q_mul( x, x ) + Q_mul( y, y ) ) ;
}