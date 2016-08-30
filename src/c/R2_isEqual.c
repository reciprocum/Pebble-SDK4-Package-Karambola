/*
   Package: R2 - float based 2D algebra.
   File   : R2_isEqual.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 19 2016
*/

#include <pebble.h>
#include "R2.h"


// a == b

bool
R2_isEqual
( const R2 *a
, const R2 *b
)
{ return (a == b) || ((a->x == b->x) && (a->y == b->y)) ; }