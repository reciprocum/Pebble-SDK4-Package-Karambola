/*
   Package: Clock3D
   File   : Clock3D_finalize.c
   Author : Afonso Santos, Portugal

   Last revision: 15h10 August 25 2016
*/

#include "Clock3D.h"


void
Clock3D_finalize
( Clock3D *this )
{
  free( MeshR3_free ( this->cube                ) )     ; this->cube                    = NULL ;

  free( Digit3D_free( this->days_leftDigitB     ) )     ; this->days_leftDigitB         = NULL ;
  free( Digit3D_free( this->days_leftDigitA     ) )     ; this->days_leftDigitA         = NULL ;
  free( Digit3D_free( this->days_rightDigitB    ) )     ; this->days_rightDigitB        = NULL ;
  free( Digit3D_free( this->days_rightDigitA    ) )     ; this->days_rightDigitA        = NULL ;

  free( Digit3D_free( this->hours_leftDigitB    ) )     ; this->hours_leftDigitB        = NULL ;
  free( Digit3D_free( this->hours_leftDigitA    ) )     ; this->hours_leftDigitA        = NULL ;
  free( Digit3D_free( this->hours_rightDigitB   ) )     ; this->hours_rightDigitB       = NULL ;
  free( Digit3D_free( this->hours_rightDigitA   ) )     ; this->hours_rightDigitA       = NULL ;
  free( RadialDial3D_free( this->hours_radial   ) )     ; this->hours_radial            = NULL ;

  free( Digit3D_free( this->minutes_leftDigitB  ) )     ; this->minutes_leftDigitB      = NULL ;
  free( Digit3D_free( this->minutes_leftDigitA  ) )     ; this->minutes_leftDigitA      = NULL ;
  free( Digit3D_free( this->minutes_rightDigitB ) )     ; this->minutes_rightDigitB     = NULL ;
  free( Digit3D_free( this->minutes_rightDigitA ) )     ; this->minutes_rightDigitA     = NULL ;
  free( RadialDial3D_free( this->minutes_radial ) )     ; this->minutes_radial          = NULL ;

  free( Digit3D_free( this->seconds_leftDigit   ) )     ; this->seconds_leftDigit       = NULL ;
  free( Digit3D_free( this->seconds_rightDigit  ) )     ; this->seconds_rightDigit      = NULL ;
  free( RadialDial3D_free( this->seconds_radial ) )     ; this->seconds_radial          = NULL ;

  free( Digit3D_free( this->second100ths_leftDigit  ) ) ; this->second100ths_leftDigit  = NULL ;
  free( Digit3D_free( this->second100ths_rightDigit ) ) ; this->second100ths_rightDigit = NULL ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  free( RadialDial3D_free( this->second100ths_radial ) ) ; this->second100ths_radial     = NULL ;
#endif
}