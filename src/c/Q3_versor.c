/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "Q3.h"


//  a = b / |b|

Q3*
Q3_versor
( Q3 *a, const Q3 *b )
{ return Q3_scaTo( a, Q_1, b ) ; }