/*
   Package: Clock3D
   File   : Clock3D_initialize.c
   Author : Afonso Santos, Portugal

   Last revision: 19h50 August 29 2016
*/

#include "Clock3D.h"


// Clock initialization.
void
Clock3D_initialize
( Clock3D *this )
{
  // ***  Initialize values  ***
  this->days              = -1 ;  // Initialy undefined.
  this->hours             = -1 ;  // Initialy undefined.
  this->hours_digitsValue = -1 ;  // Initialy undefined.
  this->hours_radialValue = -1 ;  // Initialy undefined.
  this->minutes           = -1 ;  // Initialy undefined.
  this->seconds           = -1 ;  // Initialy undefined.
  this->second100ths      = -1 ;  // Initialy undefined.

  this->digitType = CLOCK3D_DISPLAY_TYPE_DEFAULT ;

  // Animation related.
  this->days_leftDigit_animStep     = 0 ;    // Initially idle
  this->days_rightDigit_animStep    = 0 ;    // Initially idle
  this->hours_leftDigit_animStep    = 0 ;    // Initially idle
  this->hours_rightDigit_animStep   = 0 ;    // Initially idle
  this->hours_radial_animStep       = 0 ;    // Initially idle
  this->minutes_leftDigit_animStep  = 0 ;    // Initially idle
  this->minutes_rightDigit_animStep = 0 ;    // Initially idle
  this->minutes_radial_animStep     = 0 ;    // Initially idle

  // ***  Allocate meshes  ***

  // Instantiate cube mesh.
  CubeR3_config( this->cube = CubeR3_new( )
               , CUBE_SIZE               // sideLenght
               , NULL                    // inkBlinker
               ) ;

  // Instantiate DD, HH, MM, SS, 100th clock value displays.
  this->days_leftDigitA         = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->days_leftDigitB         = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->days_rightDigitA        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->days_rightDigitB        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;

  this->hours_leftDigitA        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->hours_leftDigitB        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->hours_rightDigitA       = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->hours_rightDigitB       = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->hours_radial            = RadialDial3D_new( RADIAL_DIAL_TYPE_24 ) ;

  this->minutes_leftDigitA      = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->minutes_leftDigitB      = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->minutes_rightDigitA     = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->minutes_rightDigitB     = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->minutes_radial          = RadialDial3D_new( RADIAL_DIAL_TYPE_60 ) ;

  this->seconds_leftDigit       = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->seconds_rightDigit      = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  this->seconds_radial          = RadialDial3D_new( RADIAL_DIAL_TYPE_60 ) ;

  this->second100ths_leftDigit  = Digit3D_new( CLOCK3D_SECOND100THS_DISPLAYTYPE_MAJOR ) ;
  this->second100ths_rightDigit = Digit3D_new( CLOCK3D_SECOND100THS_DISPLAYTYPE_MAJOR ) ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  this->second100ths_radial     = RadialDial3D_new( RADIAL_DIAL_TYPE_100 ) ;
#endif

  // ***  Configure stroke properties  ***

  // days
  this->days_leftDigitA ->mesh->strokeColor =
  this->days_leftDigitB ->mesh->strokeColor =
  this->days_rightDigitA->mesh->strokeColor =
  this->days_rightDigitB->mesh->strokeColor = GColorYellow
  ;

  // hours
  this->hours_leftDigitA ->mesh->strokeColor =
  this->hours_leftDigitB ->mesh->strokeColor =
  this->hours_rightDigitA->mesh->strokeColor =
  this->hours_rightDigitB->mesh->strokeColor =
  this->hours_radial     ->mesh->strokeColor = GColorGreen
  ;
  this->hours_radial->mesh->edgeAlternateMask_L2R = RADIAL_DIAL_24_EVERY6ALTERNATEEDGEMASK_L2R ;

  this->hours_radial->mesh->strokeWidthAlternate = 2 ;
  this->hours_radial->mesh->strokeColorAlternate = this->hours_radial->mesh->strokeColor ;

  // minutes
  this->minutes_leftDigitA ->mesh->strokeColor =
  this->minutes_leftDigitB ->mesh->strokeColor =
  this->minutes_rightDigitA->mesh->strokeColor =
  this->minutes_rightDigitB->mesh->strokeColor =
  this->minutes_radial     ->mesh->strokeColor = GColorRed
  ;
  this->minutes_radial->mesh->edgeAlternateMask_L2R = RADIAL_DIAL_60_EVERY5ALTERNATEEDGEMASK_L2R ;

  this->minutes_radial->mesh->strokeWidthAlternate = 2 ;
  this->minutes_radial->mesh->strokeColorAlternate = this->minutes_radial->mesh->strokeColor ;

  // seconds
  this->seconds_leftDigit ->mesh->strokeColor =
  this->seconds_rightDigit->mesh->strokeColor =
  this->seconds_radial    ->mesh->strokeColor = GColorVividCerulean
  ;

  this->seconds_radial->mesh->edgeAlternateMask_L2R = RADIAL_DIAL_60_EVERY5ALTERNATEEDGEMASK_L2R ;

  this->seconds_radial->mesh->strokeWidthAlternate = 2 ;
  this->seconds_radial->mesh->strokeColorAlternate = this->seconds_radial->mesh->strokeColor ;

  // second100ths
  this->second100ths_leftDigit ->mesh->strokeColor          =                                 // Left digit skin color.
  this->second100ths_rightDigit->mesh->strokeColorAlternate =
  this->second100ths_rightDigit->mesh->strokeColor          = GColorRichBrilliantLavender ;   // Right digit skin color.
  this->second100ths_leftDigit ->mesh->strokeColorAlternate = GColorRed ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  this->second100ths_radial->mesh->strokeColor = this->second100ths_rightDigit->mesh->strokeColor ;
  this->second100ths_radial->mesh->edgeAlternateMask_L2R  = RADIAL_DIAL_100_EVERY10ALTERNATEEDGEMASK_L2R ;
  this->second100ths_radial->mesh->strokeWidthAlternate = 2 ;

  this->second100ths_radial->mesh->strokeColorAlternate = this->second100ths_leftDigit->mesh->strokeColorAlternate ;

#endif
}