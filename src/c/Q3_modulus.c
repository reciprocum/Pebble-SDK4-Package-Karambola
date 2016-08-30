/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_modulus.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


// |v|

Q
Q3_modulus
( const Q3 *v )
{
  const Q x = v->x ;
  const Q y = v->y ;
  const Q z = v->z ;

  return Q_sqrt( Q_sq( x ) + Q_sq( y ) + Q_sq( z ) ) ;
}