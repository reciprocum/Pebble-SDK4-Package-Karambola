/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_mod.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "Q3.h"


// |v|

Q
Q3_mod
( const Q3 *v )
{
  const Q x = v->x ;
  const Q y = v->y ;
  const Q z = v->z ;

  return Q_sqrt( Q_mul( x, x ) + Q_mul( y, y ) + Q_mul( z, z ) ) ;
}