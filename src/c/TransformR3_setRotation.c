/*
   Package: TransformR3
   File   : TransformR3_setRotation.c
   Author : Afonso Santos, Portugal

   Last revision: 12h35 August 20 2016
*/

#include "TransformR3.h"


TransformR3*
TransformR3_setRotation
( TransformR3 *this
, const float  rotationX
, const float  rotationY
, const float  rotationZ
)
{
  TransformR3_setRotationX( this, rotationX ) ;
  TransformR3_setRotationY( this, rotationY ) ;
  TransformR3_setRotationZ( this, rotationZ ) ;

  return this ;  
}