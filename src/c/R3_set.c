/*
   Package: R3 - float based 3D algebra.
   File   : R3_set.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


// v := { x, y, z }

R3*
R3_set
( R3           *v
, const float   x
, const float   y
, const float   z
)
{
  v->x = x ;
  v->y = y ;
  v->z = z ;
 
  return v ;
}