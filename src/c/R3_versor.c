/*
   Package: R3 - float based 3D algebra.
   File   : R3_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "R3.h"


//  a = b / |b|

R3*
R3_versor
( R3 *a, const R3 *b )
{ return R3_scaTo( a, 1.0f, b ) ; }