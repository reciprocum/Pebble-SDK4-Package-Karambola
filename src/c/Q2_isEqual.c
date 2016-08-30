/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_isEqual.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


// a == b

bool
Q2_isEqual
( const Q2 *a
, const Q2 *b
)
{ return (a == b) || ((a->x == b->x) && (a->y == b->y)) ; }