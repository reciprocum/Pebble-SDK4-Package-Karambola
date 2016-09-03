/*
   Package: TransformR3
   File   : TransformR3.h
   Author : Afonso Santos, Portugal

   Last revision: 14h35 September 02 2016
*/

#pragma once

#include "R3.h"
#include "Matrix34.h"


typedef
struct TransformR3
{ bool                isDisabled ;   // Master public swich to enable toggling tranformation ON/OFF.
  int                 version ;      // Public versioning: to prevent uninitialized use, defer initial (or repeated) calculation of transformation matrix.
  R3                  __translation ;
  R3                  __rotation ;
  Matrix34            __transformation ;
  int                 __transformation_version ;

  struct TransformR3 *__parent ;
} TransformR3 ;


TransformR3*  TransformR3_setTranslation( TransformR3 *this, const R3 translation ) ;
TransformR3*  TransformR3_setRotation   ( TransformR3 *this, const R3 rotation    ) ;
Matrix34*     TransformR3_getTransformation( TransformR3 *this ) ;