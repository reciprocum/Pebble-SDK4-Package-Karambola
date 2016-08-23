/*
   Package: TransformR3
   File   : TransformR3_setRotationY.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 August 20 2016
*/

#include "TransformR3.h"


TransformR3*
TransformR3_setRotationY
( TransformR3 *this
, const float  rotation
)
{
  if (this->__rotationY != rotation)
  {
    this->__rotationY = rotation ;
    this->version++ ;
  }

  return this ;  
}