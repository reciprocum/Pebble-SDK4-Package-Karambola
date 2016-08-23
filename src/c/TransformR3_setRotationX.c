/*
   Package: TransformR3
   File   : TransformR3_setRotationX.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 August 20 2016
*/

#include "TransformR3.h"


TransformR3*
TransformR3_setRotationX
( TransformR3 *this
, const float  rotation
)
{
  if (this->__rotationX != rotation)
  {
    this->__rotationX = rotation ;
    this->version++ ;
  }

  return this ;  
}