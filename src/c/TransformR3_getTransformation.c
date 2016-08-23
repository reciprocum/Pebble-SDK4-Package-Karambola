/*
   Package: TransformR3
   File   : TransformR3_getTransformation.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 August 20 2016
*/

#include "TransformR3.h"


Matrix34*
TransformR3_getTransformation
( TransformR3 *this )
{
  if (this->isDisabled | (this->version == 0))
    return NULL ;

  if (this->__transformation_version != this->version)
  {
    Matrix34_transformation( &this->__transformation, this->__rotationX, this->__rotationY, this->__rotationZ, &this->__translation ) ;
    this->__transformation_version = this->version ;
  }

  return &this->__transformation ;  
}