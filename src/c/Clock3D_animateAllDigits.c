/*
   Package: Clock3D
   File   : Clock3D_animateAllDigits.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 25 2016
*/

#include "Clock3D.h"


void
Clock3D_animateAllDigits
( Clock3D  *this )
{
  if (this->days_leftDigit_animStep == 0)
  {
    Digit3D_setValue( this->days_leftDigitB, this->days_leftDigitA->value ) ;                          // B side inherits A side value.
    this->days_leftDigitB->mesh->state.isDisabled = this->days_leftDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    this->days_leftDigit_animStep = 1 ;
  }

  if (this->days_rightDigit_animStep == 0)
  {
    Digit3D_setValue( this->days_rightDigitB, this->days_rightDigitA->value ) ;                          // B side inherits A side value.
    this->days_rightDigitB->mesh->state.isDisabled = this->days_rightDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    this->days_rightDigit_animStep = 1 ;
  }

  if (this->hours_leftDigit_animStep == 0)
  {
    Digit3D_setValue( this->hours_leftDigitB, this->hours_leftDigitA->value ) ;                          // B side inherits A side value.
    this->hours_leftDigitB->mesh->state.isDisabled = this->hours_leftDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    this->hours_leftDigit_animStep = 1 ;
  }

  if (this->hours_rightDigit_animStep == 0)
  {
    Digit3D_setValue( this->hours_rightDigitB, this->hours_rightDigitA->value ) ;                          // B side inherits A side value.
    this->hours_rightDigitB->mesh->state.isDisabled = this->hours_rightDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    this->hours_rightDigit_animStep = 1 ;
  }

  if (this->minutes_leftDigit_animStep == 0)
  {
    Digit3D_setValue( this->minutes_leftDigitB, this->minutes_leftDigitA->value ) ;                          // B side inherits A side value.
    this->minutes_leftDigitB->mesh->state.isDisabled = this->minutes_leftDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    this->minutes_leftDigit_animStep = 1 ;
  }

  if (this->minutes_rightDigit_animStep == 0)
  {
    Digit3D_setValue( this->minutes_rightDigitB, this->minutes_rightDigitA->value ) ;                          // B side inherits A side value.
    this->minutes_rightDigitB->mesh->state.isDisabled = this->minutes_rightDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    this->minutes_rightDigit_animStep = 1 ;
  }
}