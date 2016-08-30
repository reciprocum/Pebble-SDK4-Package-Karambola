/*
   Package: R2 - float based 2D algebra.
   File   : R2_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 17h50 August 19 2016
*/

#include "R2.h"


//  v = v / |v|

R2*
R2_versor
( R2 *v )
{ return R2_scale( 1.0f, v ) ; }