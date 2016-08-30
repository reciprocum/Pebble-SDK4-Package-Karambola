/*
   Package: Clock3D
   File   : Clock3D_animateAllRadials.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 25 2016
*/

#include "Clock3D.h"


void
Clock3D_animateAllRadials
( Clock3D  *this )
{
  if (this->minutes_radial_animStep == 0)
  {
    this->minutes_radial_valueOnAnimStop = this->minutes_radial->value ;
    this->minutes_radial_animStep        = 1 ;
  }

  if (this->hours_radial_animStep == 0)
  {
    this->hours_radial_valueOnAnimStop = this->hours_radial->value ;
    this->hours_radial_animStep        = 1 ;
  }
}