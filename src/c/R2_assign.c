/*
   Package: R2 - float based 2D algebra.
   File   : R2_assign.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 19 2016
*/

#include "R2.h"


// b := a

R2*
R2_assign
( R2       *b
, const R2 *a
)
{
  b->x = a->x ;
  b->y = a->y ;
 
  return b ;
}