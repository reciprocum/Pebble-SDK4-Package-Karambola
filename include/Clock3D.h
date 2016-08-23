/*
   Package: Clock3D
   File   : Clock3D.h
   Author : Afonso Santos, Portugal

   Last revision: 18h40 August 22 2016
*/

#pragma once

#include "Cube.h"
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


extern Digit2D_Type         clock_displayType ;

// Need to expose digit meshes because of access to blinker.
extern Digit3D    *clock_days_leftDigitA ;
extern Digit3D    *clock_days_leftDigitB ;
extern Digit3D    *clock_days_rightDigitA ;
extern Digit3D    *clock_days_rightDigitB ;

extern Digit3D    *clock_hours_leftDigitA ;
extern Digit3D    *clock_hours_leftDigitB ;
extern Digit3D    *clock_hours_rightDigitA ;
extern Digit3D    *clock_hours_rightDigitB ;

extern Digit3D    *clock_minutes_leftDigitA ;
extern Digit3D    *clock_minutes_leftDigitB ;
extern Digit3D    *clock_minutes_rightDigitA ;
extern Digit3D    *clock_minutes_rightDigitB ;

extern Digit3D    *clock_seconds_leftDigit ;
extern Digit3D    *clock_seconds_rightDigit ;

extern Digit3D    *clock_second100ths_leftDigit ;
extern Digit3D    *clock_second100ths_rightDigit ;


void Clock3D_initialize         ( ) ;
bool Clock3D_isAnimated         ( ) ;
void Clock3D_animateAllDigits   ( ) ;
void Clock3D_animateAllRadials  ( ) ;
void Clock3D_animateAll         ( ) ;
void Clock3D_second100ths_update( ) ;
void Clock3D_updateDDHHMMSS     ( ) ;
void Clock3D_config             ( Digit2D_Type pDigitType ) ;
void Clock3D_updateAnimation    ( const int pMaxAnimSteps ) ;
void Clock3D_setDisplayType     ( Digit2D_Type pDigitType ) ;
void Clock3D_cycleDisplayType   ( ) ;
void Clock3D_finalize           ( ) ;

void
Clock3D_setTime_DDHHMMSS
( const uint8_t  pDays
, const uint8_t  pHours
, const uint8_t  pMinutes
, const uint8_t  pSeconds
) ;

void
Clock3D_draw
( GContext                      *gCtx
//, Clock3D                     *this    // TODO
, const Cam3D                   *cam
, const int                      w
, const int                      h
, const Mesh3D_TransparencyMode  transparency
) ;