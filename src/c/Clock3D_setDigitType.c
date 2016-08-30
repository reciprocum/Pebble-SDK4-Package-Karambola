/*
   Package: Clock3D
   File   : Clock3D_setDigitType.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 25 2016
*/

#include "Clock3D.h"


void
Clock3D_setDigitType
( Clock3D     *this
, Digit2D_Type pDigitType
)
{
  if (pDigitType != this->digitType)
    Clock3D_config( this, this->digitType = pDigitType ) ;
}