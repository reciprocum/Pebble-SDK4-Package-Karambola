/*
   Package: R3 - float based 3D algebra.
   File   : R3_isEqual.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


// a == b

bool
R3_isEqual
( const R3 *a
, const R3 *b
)
{ return (a == b) || ((a->x == b->x) && (a->y == b->y) && (a->z == b->z)) ; }