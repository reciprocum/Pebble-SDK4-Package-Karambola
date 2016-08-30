/*
   Package: R3 - float based 3D algebra.
   File   : R3_assign.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


// b := a

R3*
R3_assign
( R3       *b
, const R3 *a
)
{
  b->x = a->x ;
  b->y = a->y ;
  b->z = a->z ;

  return b ;
}