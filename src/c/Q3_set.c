/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_set.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


// v := { x, y, z }

Q3*
Q3_set
( Q3       *v
, const Q   x
, const Q   y
, const Q   z
)
{
  v->x = x ;
  v->y = y ;
  v->z = z ;
 
  return v ;
}