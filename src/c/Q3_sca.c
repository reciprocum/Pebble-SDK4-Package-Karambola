/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_sca.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "Q3.h"


// s := k * v

Q3*
Q3_sca
(       Q3 *s
, const Q	  k
, const Q3 *v
)
{
  s->x = Q_mul( k, v->x ) ;
  s->y = Q_mul( k, v->y ) ;
  s->z = Q_mul( k, v->z ) ;

  return s ;
}