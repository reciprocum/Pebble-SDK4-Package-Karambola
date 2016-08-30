/*
   Package: Matrix34
   File   : Matrix34_transformation.c
   Author : Afonso Santos, Portugal

   Last revision: 10h10 August 30 2016
*/

#include "Matrix34.h"


Matrix34*
Matrix34_transformation
( Matrix34  *T
, const R3   rotation
, const R3   translation
)
{
  Matrix34_setTranslation( Matrix34_rotation( T, rotation.x, rotation.y, rotation.z )
                         , translation
                         ) ;

  return T ;
}