/*
   Package: TransformR3
   File   : TransformR3_setRotation.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 September 14 2016
*/

#include "TransformR3.h"


TransformR3*
TransformR3_setRotation
( TransformR3 *this
, const R3     rotation
)
{
  if (!R3_isEqual( &this->__rotation, &rotation ))
  {
    this->__rotation = rotation ;
    this->version++ ;
  }

  return this ;  
}