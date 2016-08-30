/*
   Package: Clock3D
   File   : Clock3D_cycleDigitType.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 25 2016
*/

#include "Clock3D.h"


void
Clock3D_cycleDigitType
( Clock3D  *this )
{
  switch (this->digitType)
  {
    case DIGIT2D_CURVYBONESKIN:
      Clock3D_setDigitType( this, DIGIT2D_CURVYSKINBONE ) ;
      break ;

    case DIGIT2D_CURVYSKINBONE:
      Clock3D_setDigitType( this, DIGIT2D_CURVYSKIN ) ;
      break ;

    case DIGIT2D_CURVYSKIN:
      Clock3D_setDigitType( this, DIGIT2D_CURVYBONE ) ;
      break ;

    case DIGIT2D_CURVYBONE:
      Clock3D_setDigitType( this, DIGIT2D_7SEGSKINBONE ) ;
      break ;

    case DIGIT2D_7SEGSKINBONE:
      Clock3D_setDigitType( this, DIGIT2D_7SEGBONESKIN ) ;
      break ;

    case DIGIT2D_7SEGBONESKIN:
      Clock3D_setDigitType( this, DIGIT2D_7SEGSKIN ) ;
      break ;

    case DIGIT2D_7SEGSKIN:
      Clock3D_setDigitType( this, DIGIT2D_7SEGBONE ) ;
      break ;

    case DIGIT2D_7SEGBONE:
      Clock3D_setDigitType( this, CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
      break ;

    default:
      Clock3D_setDigitType( this, CLOCK3D_DISPLAY_TYPE_DEFAULT ) ;
      break ;
  } ;
}