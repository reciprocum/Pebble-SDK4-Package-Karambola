/*
   Package: TransformR3
   File   : TransformR3_rotateY.c
   Author : Afonso Santos, Portugal

   Last revision: 11h55 August 30 2016
*/

#include "TransformR3.h"


R3*
TransformR3_rotateY
( R3          *this
, const float  angle
)
{
  static TransformR3  transform ;
  TransformR3_setRotation( &transform, (R3){ .x = 0.0f, .y = angle, .z = 0.0f } ) ;

  // this := this X transform.
  // Rotate this point around y-axis.
  Matrix34_transform( this, this, TransformR3_getTransformation( &transform ) ) ;

  return this ;  
}