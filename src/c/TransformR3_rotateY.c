/*
   Package: TransformR3
   File   : TransformR3_rotateY.c
   Author : Afonso Santos, Portugal

   Last revision: 21h25 August 20 2016
*/

#include "TransformR3.h"


R3*
TransformR3_rotateY
( R3          *this
, const float  rotation
)
{
  static TransformR3  transform ;
  TransformR3_setRotation( &transform, 0.0f, rotation, 0.0f ) ;

  // this := this X transform.
  // Rotate this point around y-axis.
  Matrix34_transform( this, this, TransformR3_getTransformation( &transform ) ) ;

  return this ;  
}