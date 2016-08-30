/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_isEqual.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


// a == b

bool
Q3_isEqual
( const Q3 *a
, const Q3 *b
)
{ return (a == b) || ((a->x == b->x) && (a->y == b->y) && (a->z == b->z)) ; }