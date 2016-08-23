/*
   Package: R3
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