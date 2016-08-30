/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_dotProduct.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


// a . b

Q
Q3_dotProduct
( const Q3 *a
, const Q3 *b
)
{
  // a->x * b->x  +  a->y * b->y  +  a->z * b->z
  return Q_mul( a->x, b->x )
       + Q_mul( a->y, b->y )
       + Q_mul( a->z, b->z )
       ;
}