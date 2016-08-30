/*
   Package: R3 - float based 3D algebra.
   File   : R3_versor.c
   Author : Afonso Santos, Portugal

   Last revision: 12h05 August 20 2016
*/

#include "R3.h"


//  v := v / |v|

R3*
R3_versor
( R3 *v )
{ return R3_scale( 1.0f, v ) ; }