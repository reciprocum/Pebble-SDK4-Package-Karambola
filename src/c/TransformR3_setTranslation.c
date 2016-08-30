/*
   Package: TransformR3
   File   : TransformR3_setTranslation.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 August 20 2016
*/

#include "TransformR3.h"


TransformR3*
TransformR3_setTranslation
( TransformR3 *this
, const R3     translation
)
{
  if (!R3_isEqual( &this->__translation, &translation ))
  {
    R3_assign( &this->__translation, &translation ) ;
    this->version++ ;
  }

  return this ;  
}