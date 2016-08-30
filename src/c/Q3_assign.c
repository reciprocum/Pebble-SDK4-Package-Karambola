/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_assign.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


// b := a

Q3*
Q3_assign
( Q3       *b
, const Q3 *a
)
{
  b->x = a->x ;
  b->y = a->y ;
  b->z = a->z ;
 
  return b ;
}