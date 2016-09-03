/*
   Package: R2 - float based 2D algebra.
   File   : R2_rotZrad.c
   Author : Afonso Santos, Portugal

   Last revision: 15h48 September 02 2016
*/

#include "FastMath.h"
#include "R2.h"


R2*
R2_rotRad
(       R2    *a
, const R2    *b
, const float  angleRad
)
{
  const float sin = FastMath_sinRad( angleRad ) ;
  const float cos = FastMath_cosRad( angleRad ) ;

  const float x = b->x * cos  -  b->y * sin ;
  const float y = b->x * sin  +  b->y * cos ;

  a->x = x ;
  a->y = y ;

  return a ;  
}