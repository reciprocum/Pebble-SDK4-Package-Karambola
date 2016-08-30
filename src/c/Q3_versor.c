/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 29 2016
*/

#include "Q3.h"


//  v := v / |v|

Q3*
Q3_versor
( Q3 *v )
{ return Q3_scale( Q_1, v ) ; }