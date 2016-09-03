/*
   Package: R3 - float based 3D algebra.
   File   : R3_rotZrad.c
   Author : Afonso Santos, Portugal

   Last revision: 14h18 September 02 2016
*/

#include "FastMath.h"
#include "R3.h"


R3*
R3_rotZrad
(       R3    *a
, const R3    *b
, const float  angleRad
)
{
  const float sin = FastMath_sinRad( angleRad ) ;
  const float cos = FastMath_cosRad( angleRad ) ;

  const float x = b->x * cos  -  b->y * sin ;
  const float y = b->x * sin  +  b->y * cos ;

  a->x = x ;
  a->y = y ;
  a->z = b->z ;

  return a ;  
}