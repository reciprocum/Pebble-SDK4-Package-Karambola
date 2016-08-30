/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_set.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


// v := { x, y }

Q2*
Q2_set
( Q2     *v
, const Q x
, const Q y
)
{
  v->x = x ;
  v->y = y ;

  return v ;
}