/*
   Package: R2 - float based 2D algebra.
   File   : R2_sca.c
   Author : Afonso Santos, Portugal

   Last revision: 06h65 September 02 2016
*/

#include "R2.h"


// b := k * a

R2*
R2_sca
(       R2   *b
, const float	k
, const R2   *a
)
{
  b->x = k * a->x ;
  b->y = k * a->y ;
 
  return b ;
}