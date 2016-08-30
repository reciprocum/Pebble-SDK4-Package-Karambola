/*
   Package: Clock3D
   File   : Clock3D_isAnimated.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 25 2016
*/

#include "Clock3D.h"


bool
Clock3D_isAnimated
( Clock3D  *this )
{
  return this->days_leftDigit_animStep > 0
      || this->days_rightDigit_animStep > 0
      || this->hours_leftDigit_animStep > 0
      || this->hours_rightDigit_animStep > 0
      || this->hours_radial_animStep > 0
      || this->minutes_leftDigit_animStep > 0
      || this->minutes_rightDigit_animStep > 0
      || this->minutes_radial_animStep > 0
       ;
}