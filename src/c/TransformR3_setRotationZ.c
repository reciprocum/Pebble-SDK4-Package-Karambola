/*
   Package: TransformR3
   File   : TransformR3_setRotationZ.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 August 20 2016
*/

#include "TransformR3.h"


TransformR3*
TransformR3_setRotationZ
( TransformR3 *this
, const float  rotation
)
{
  if (this->__rotationZ != rotation)
  {
    this->__rotationZ = rotation ;
    this->version++ ;
  }

  return this ;  
}