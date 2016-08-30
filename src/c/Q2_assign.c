/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_assign.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


// b := a

Q2*
Q2_assign
( Q2       *b
, const Q2 *a
)
{
  b->x = a->x ;
  b->y = a->y ;
 
  return b ;
}