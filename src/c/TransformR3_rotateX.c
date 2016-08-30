/*
   Package: TransformR3
   File   : TransformR3_rotateX.c
   Author : Afonso Santos, Portugal

   Last revision: 11h55 August 30 2016
*/

#include "TransformR3.h"


R3*
TransformR3_rotateX
( R3          *this
, const float  angle
)
{
  static TransformR3  transform ;
  TransformR3_setRotation( &transform, (R3){ .x = angle, .y = 0.0f, .z = 0.0f } ) ;

  // this := this X transform.
  // Rotate this point around x-axis.
  Matrix34_transform( this, this, TransformR3_getTransformation( &transform ) ) ;

  return this ;  
}