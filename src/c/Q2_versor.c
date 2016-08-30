/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 29 2016
*/

#include "Q2.h"


//  v = v / |v|

Q2*
Q2_versor
( Q2 *v )
{ return Q2_scale( Q_1, v ) ; }