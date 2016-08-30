/*
   Package: Clock3D
   File   : Clock3D.h
   Author : Afonso Santos, Portugal

   Last revision: 18h40 August 29 2016
*/

#pragma once

#include "CubeR3.h"
#include "Digit3D.h"
#include "RadialDial3D.h"


// World objects & parameters

// WARNING!: DIGIT2D_CURVYBONESKIN consumes a LOT of RAM !!!
#define  CLOCK3D_DISPLAY_TYPE_MAJOR    DIGIT2D_CURVYBONESKIN
#define  CLOCK3D_DISPLAY_TYPE_DEFAULT  DIGIT2D_CURVYBONESKIN

// Comment next line if you need/want to omit the radial dial on the second100ths face (~3KB RAM savings).
#define  CLOCK3D_SECOND100THS_RADIAL
#define  CLOCK3D_SECOND100THS_DISPLAYTYPE_MAJOR  DIGIT2D_7SEGSKINBONE
#define  CLOCK3D_SECOND100THS_DISPLAYTYPE        DIGIT2D_7SEGSKINBONE

#define  CUBE_SIZE            1.0f
#define  CUBE_HALF            (0.50f * CUBE_SIZE)
#define  RADIAL_INNER_RADIUS  (0.80f * CUBE_HALF)
#define  RADIAL_OUTER_RADIUS  (0.97f * CUBE_HALF)


typedef struct
{
  MeshR3       *cube ;

  Digit2D_Type  digitType ;

  int8_t        days ;
  Digit3D      *days_leftDigitA ;
  Digit3D      *days_leftDigitB ;
  Digit3D      *days_rightDigitA ;
  Digit3D      *days_rightDigitB ;

  int8_t        hours ;
  int8_t        hours_digitsValue ;
  int8_t        hours_radialValue ;
  Digit3D      *hours_leftDigitA ;
  Digit3D      *hours_leftDigitB ;
  Digit3D      *hours_rightDigitA ;
  Digit3D      *hours_rightDigitB ;
  RadialDial3D *hours_radial ;
  unsigned int  hours_radial_valueOnAnimStop ;

  int8_t        minutes ;
  Digit3D      *minutes_leftDigitA ;
  Digit3D      *minutes_leftDigitB ;
  Digit3D      *minutes_rightDigitA ;
  Digit3D      *minutes_rightDigitB ;
  RadialDial3D *minutes_radial ;
  unsigned int  minutes_radial_valueOnAnimStop ;

  int8_t        seconds ;
  Digit3D      *seconds_leftDigit ;
  Digit3D      *seconds_rightDigit ;
  RadialDial3D *seconds_radial ;

  int8_t        second100ths ;
  Digit3D      *second100ths_leftDigit ;
  Digit3D      *second100ths_rightDigit ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  RadialDial3D *second100ths_radial ;
#endif

  // Animation related.
  int    days_leftDigit_animStep ;
  int    days_rightDigit_animStep ;
  int    hours_leftDigit_animStep ;
  int    hours_rightDigit_animStep ;
  int    hours_radial_animStep ;
  int    minutes_leftDigit_animStep ;
  int    minutes_rightDigit_animStep ;
  int    minutes_radial_animStep ;
} Clock3D ;



void Clock3D_initialize         ( Clock3D *this ) ;
bool Clock3D_isAnimated         ( Clock3D *this ) ;
void Clock3D_animateAllDigits   ( Clock3D *this ) ;
void Clock3D_animateAllRadials  ( Clock3D *this ) ;
void Clock3D_animateAll         ( Clock3D *this ) ;
void Clock3D_second100ths_update( Clock3D *this ) ;
void Clock3D_updateDDHHMMSS     ( Clock3D *this ) ;
void Clock3D_config             ( Clock3D *this, Digit2D_Type pDigitType ) ;
void Clock3D_updateAnimation    ( Clock3D *this, const int pMaxAnimSteps ) ;
void Clock3D_setDigitType       ( Clock3D *this, Digit2D_Type pDigitType ) ;
void Clock3D_cycleDigitType     ( Clock3D *this ) ;
void Clock3D_finalize           ( Clock3D *this ) ;

void
Clock3D_setTime_DDHHMMSS
( Clock3D       *this
, const uint8_t  pDays
, const uint8_t  pHours
, const uint8_t  pMinutes
, const uint8_t  pSeconds
) ;

void
Clock3D_draw
( GContext               *gCtx
, Clock3D                *this
, const CamR3            *cam
, const int               w
, const int               h
, const MeshTransparency  transparency
) ;