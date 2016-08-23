/*
   Package: Matrix34
   File   : Matrix34_transformation.c
   Author : Afonso Santos, Portugal

   Last revision: 13h10 August 21 2016
*/

#include "Matrix34.h"


Matrix34*
Matrix34_transformation
( Matrix34     *T
, const float   rotationX
, const float   rotationY
, const float   rotationZ
, const R3     *translation
)
{
  Matrix34_setTranslation( Matrix34_rotation( T, rotationX, rotationY, rotationZ )
                         , translation
                         ) ;

  return T ;
}