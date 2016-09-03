/*
   Package: R2 - float based 2D algebra.
   File   : R2_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "R2.h"


//  a = b / |b|

R2*
R2_versor
( R2 *a, const R2 *b )
{ return R2_scaTo( a, 1.0f, b ) ; }