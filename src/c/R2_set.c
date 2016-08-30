/*
   Package: R2 - float based 2D algebra.
   File   : R2_set.c
   Author : Afonso Santos, Portugal

   Last revision: 16h55 August 19 2016
*/

#include <pebble.h>
#include "R2.h"


// v := { x, y }

R2*
R2_set
( R2         *v
, const float x
, const float y
)
{
  v->x = x ;
  v->y = y ;
 
  return v ;
}