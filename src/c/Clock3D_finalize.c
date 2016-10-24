/*
   Package: Clock3D
   File   : Clock3D_finalize.c
   Author : Afonso Santos, Portugal

   Last revision: 15h10 October 20 2016
*/

#include "Clock3D.h"


void
Clock3D_finalize
( Clock3D *this )
{
  MeshR3_free( this->cube ) ;

  Digit3D_free( this->days_leftDigitB ) ;
  Digit3D_free( this->days_leftDigitA ) ;
  Digit3D_free( this->days_rightDigitB ) ;
  Digit3D_free( this->days_rightDigitA ) ;

  Digit3D_free( this->hours_leftDigitB ) ;
  Digit3D_free( this->hours_leftDigitA ) ;
  Digit3D_free( this->hours_rightDigitB ) ;
  Digit3D_free( this->hours_rightDigitA ) ;

  Digit3D_free( this->minutes_leftDigitB ) ;
  Digit3D_free( this->minutes_leftDigitA ) ;
  Digit3D_free( this->minutes_rightDigitB ) ;
  Digit3D_free( this->minutes_rightDigitA ) ;

  Digit3D_free( this->seconds_leftDigit ) ;
  Digit3D_free( this->seconds_rightDigit ) ;

  Digit3D_free( this->second100ths_leftDigit ) ;
  Digit3D_free( this->second100ths_rightDigit ) ;

  RadialDial3D_free( this->hours_radial ) ;
  RadialDial3D_free( this->minutes_radial ) ;
  RadialDial3D_free( this->seconds_radial ) ;
  RadialDial3D_free( this->second100ths_radial ) ;
}