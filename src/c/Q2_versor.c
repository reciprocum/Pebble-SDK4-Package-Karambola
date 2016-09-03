/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 06h15 September 02 2016
*/

#include "Q2.h"


//  a = b / |b|

Q2*
Q2_versor
( Q2 *a, const Q2 *b )
{ return Q2_scaTo( a, Q_1, b ) ; }