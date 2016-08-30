/*
   Package: TransformR3
   File   : TransformR3_rotateZ.c
   Author : Afonso Santos, Portugal

   Last revision: 11h55 August 30 2016
*/

#include "TransformR3.h"


R3*
TransformR3_rotateZ
( R3          *this
, const float  angle
)
{
  static TransformR3  transform ;
  TransformR3_setRotation( &transform, (R3){ .x = 0.0f, .y = 0.0f, .z = angle } ) ;

  // this := this X transform.
  // Rotate this point around z-axis.
  Matrix34_transform( this, this, TransformR3_getTransformation( &transform ) ) ;

  return this ;  
}