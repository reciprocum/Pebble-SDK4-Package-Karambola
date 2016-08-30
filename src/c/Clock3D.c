/*
   Package: Clock3D
   File   : Clock3D.c
   Author : Afonso Santos, Portugal

   Last revision: 10h10 August 30 2016
*/

#include <pebble.h>
#include "FastMath.h"
#include "Clock3D.h"


// Between the cube, the segment displays and the radial dials the biggest mesh has no more than 200 vertices.
GPoint __MeshR3_vertex_screenPoint[200] ;

// Externaly provided interpolation tables.
extern float     *spinRotationFraction    ;
extern float     *animRotationFraction    ;
extern float     *animTranslationFraction ;


// Clock configuration.

void
Clock3D_days_leftDigit_config
( Clock3D           *this
, const int          pAnimStep
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.8 * CUBE_SIZE ;
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap ) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( this->days_leftDigitA
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x =-digitShift                    // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = 0.0f                          // rotationX (face FRONT)
                      , .y = animRotation                  // rotationY
                      , .z = DEG_090                       // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = 0.0f
                      , .z = CUBE_HALF + animTranslation   // positionOfCenter (TOP)
                      }
                ) ;

  Digit3D_config( this->days_leftDigitB
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x =-digitShift                   // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = 0.0f                         // rotationX (face FRONT)
                      , .y = DEG_180 + animRotation       // rotationY
                      , .z = DEG_090                      // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = 0.0f
                      , .z = CUBE_HALF + animTranslation  // positionOfCenter (TOP)
                      }
                ) ;
}

void
Clock3D_days_rightDigit_config
( Clock3D           *this
, const int          pAnimStep
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.8 * CUBE_SIZE ;
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap ) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  const float rightDigitA_valueShift = this->days_leftDigitA->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( this->days_rightDigitA
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x = rightDigitA_valueShift       // shift right
                      , .y = 0.0f
                      }
                , (R3){ .x = 0.0f                         // rotationX (face FRONT)
                      , .y = animRotation                 // rotationY
                      , .z = DEG_090                      // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = 0.0f
                      , .z = CUBE_HALF + animTranslation  // positionOfCenter (TOP)
                      }
                ) ;

  const float rightDigitB_valueShift = this->days_leftDigitB->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( this->days_rightDigitB
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x = rightDigitB_valueShift       // shift right
                      , .y = 0.0f
                      }
                , (R3){ .x = 0.0f                         // rotationX (face FRONT)
                      , .y = DEG_180 + animRotation       // rotationY
                      , .z = DEG_090                      // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = 0.0f
                      , .z = CUBE_HALF + animTranslation  // positionOfCenter (TOP)
                      }
                ) ;
}


void
Clock3D_hours_leftDigit_config
( Clock3D           *this
, const int          pAnimStep
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( this->hours_leftDigitA
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x =-digitShift                    // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_180                       // rotationX
                      , .y = DEG_270 + animRotation        // rotationY
                      , .z = DEG_270                       // rotationZ
                      }
                , (R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                      , .y = 0.0f
                      , .z = 0.0f
                      }
                ) ;

  Digit3D_config( this->hours_leftDigitB
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x =-digitShift                    // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_180                       // rotationX
                      , .y = DEG_090 + animRotation        // rotationY
                      , .z = DEG_270                       // rotationZ
                      }
                , (R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                      , .y = 0.0f
                      , .z = 0.0f
                      }
                ) ;
}


void
Clock3D_hours_rightDigit_config
( Clock3D           *this
, const int          pAnimStep
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  const float rightDigitA_valueShift = this->hours_leftDigitA->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( this->hours_rightDigitA
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x = rightDigitA_valueShift        // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_180                       // rotationX
                      , .y = DEG_270 + animRotation        // rotationY
                      , .z = DEG_270                       // rotationZ
                      }
                , (R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                      , .y = 0.0f
                      , .z = 0.0f
                      }
                ) ;

  const float rightDigitB_valueShift = this->hours_leftDigitB->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( this->hours_rightDigitB
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x = rightDigitB_valueShift        // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_180                       // rotationX
                      , .y = DEG_090 + animRotation        // rotationY
                      , .z = DEG_270                       // rotationZ
                      }
                , (R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                      , .y = 0.0f
                      , .z = 0.0f
                      }
                ) ;
}


void
Clock3D_hours_radial_config
( Clock3D  *this
, const int pAnimStep
)
{
  const float digitHeight     = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  RadialDial3D_config( this->hours_radial
                     , this->hours_digitsValue > 9  ?  RADIAL_DIAL_SHAPE_SQUARE
                                                    :  RADIAL_DIAL_SHAPE_CIRCLE
                     , RADIAL_INNER_RADIUS                  // innerRadius
                     , RADIAL_OUTER_RADIUS                  // outerRadius
                     , (R3){ .x = DEG_180                   // rotationX
                           , .y = DEG_270                   // rotationY
                           , .z = DEG_270                   // rotationZ
                           }
                     , (R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                           , .y = 0.0
                           , .z = 0.0
                           }
                     ) ;
}


void
Clock3D_minutes_leftDigit_config
( Clock3D           *this
, const int          pAnimStep
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( this->minutes_leftDigitA
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x =-digitShift                     // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x =-DEG_090 + animRotation         // rotationX (face FRONT)
                      , .y = DEG_180                        // rotationY (mirror turn)
                      , .z = 0.0f                           // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = CUBE_HALF + animTranslation    // positionOfCenter (NEAR)
                      , .z = 0.0f
                      }
                ) ;

  Digit3D_config( this->minutes_leftDigitB
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x =-digitShift                    // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_090 + animRotation        // rotationX (face FRONT)
                      , .y = DEG_180                       // rotationY (mirror turn)
                      , .z = 0.0f                          // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = CUBE_HALF + animTranslation   // positionOfCenter (NEAR)
                      , .z = 0.0f
                      }
                ) ;
}


void
Clock3D_minutes_rightDigit_config
( Clock3D           *this
, const int          pAnimStep
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;
  
  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( this->minutes_rightDigitA
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x = digitShift                     // shift right
                      , .y = 0.0f
                      }
                , (R3){ .x =-DEG_090 + animRotation         // rotationX (face FRONT)
                      , .y = DEG_180                        // rotationY (mirror turn)
                      , .z = 0.0f                           // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = CUBE_HALF + animTranslation    // positionOfCenter (NEAR)
                      , .z = 0.0f
                      }
                ) ;

  Digit3D_config( this->minutes_rightDigitB
                , pDigitType
                , (R2){ .x = digitWidth                    // width
                      , .y = digitHeight                   // height
                      }
                , (R2){ .x = digitShift                     // shift right
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_090 + animRotation         // rotationX (face FRONT)
                      , .y = DEG_180                        // rotationY (mirror turn)
                      , .z = 0.0f                           // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y = CUBE_HALF + animTranslation    // positionOfCenter (NEAR)
                      , .z = 0.0f
                      }
                ) ;
}


void
Clock3D_minutes_radial_config
( Clock3D  *this
, const int pAnimStep
)
{
  const float digitHeight     = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  RadialDial3D_config( this->minutes_radial
                     , RADIAL_DIAL_SHAPE_SQUARE
                     , RADIAL_INNER_RADIUS                       // innerRadius
                     , RADIAL_OUTER_RADIUS                       // outerRadius
                     , (R3){ .x =-DEG_090                        // rotationX (face FRONT)
                           , .y = DEG_180                        // rotationY (mirror turn)
                           , .z = 0.0f                           // rotationZ
                           }
                     , (R3){ .x = 0.0f
                           , .y = CUBE_HALF + animTranslation    // positionOfCenter (NEAR)
                           , .z = 0.0f
                           }
                     ) ;
}


void
Clock3D_seconds_leftDigit_config
( Clock3D           *this
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  Digit3D_config( this->seconds_leftDigit
                , pDigitType
                , (R2){ .x = digitWidth            // width
                      , .y = digitHeight           // height
                      }
                , (R2){ .x =-digitShift            // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_180               // rotationX
                      , .y = DEG_090               // rotationY
                      , .z = DEG_090               // rotationZ
                      }
                , (R3){ .x =-CUBE_HALF             // positionOfCenter (RIGHT)
                      , .y = 0.0
                      , .z = 0.0
                      }
                ) ;
}


void
Clock3D_seconds_rightDigit_config
( Clock3D           *this
, const Digit2D_Type pDigitType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;
    
  Digit3D_config( this->seconds_rightDigit
                , pDigitType
                , (R2){ .x = digitWidth            // width
                      , .y = digitHeight           // height
                      }
                , (R2){ .x = digitShift            // shift right
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_180               // rotationX
                      , .y = DEG_090               // rotationY
                      , .z = DEG_090               // rotationZ
                      }
                , (R3){ .x =-CUBE_HALF             // positionOfCenter (RIGHT)
                      , .y = 0.0f
                      , .z = 0.0f
                      }
                ) ;
}


void
Clock3D_seconds_radial_config
( Clock3D  *this )
{
  RadialDial3D_config( this->seconds_radial
                     , RADIAL_DIAL_SHAPE_SQUARE
                     , RADIAL_INNER_RADIUS       // innerRadius
                     , RADIAL_OUTER_RADIUS       // outerRadius
                     , (R3){ .x = DEG_180        // rotationX
                           , .y = DEG_090        // rotationY
                           , .z = DEG_090        // rotationZ
                           }
                     , (R3){ .x = -CUBE_HALF     // positionOfCenter (RIGHT)
                           , .y = 0.0f
                           , .z = 0.0f
                           }
                     ) ;
}


void
Clock3D_second100ths_leftDigit_config
( Clock3D *this )
{
#ifdef CLOCK3D_SECOND100THS_RADIAL
  const float digitHeight = 0.6 * CUBE_SIZE ;   // Outer rim left for radial dial.
#else
  const float digitHeight = 0.8 * CUBE_SIZE ;   // No space left for radial dial.
#endif

  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  Digit3D_config( this->second100ths_leftDigit
                , CLOCK3D_SECOND100THS_DISPLAYTYPE
                , (R2){ .x = digitWidth            // width
                      , .y = digitHeight           // height
                      }
                , (R2){ .x =-digitShift             // shift left
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_090                // rotationX (vertical)
                      , .y = 0.0f                   // rotationY
                      , .z = 0.0f                   // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y =-CUBE_HALF              // positionOfCenter (FAR)
                      , .z = 0.0f
                      }
                ) ;
}


void
Clock3D_second100ths_rightDigit_config
( Clock3D *this )
{
#ifdef CLOCK3D_SECOND100THS_RADIAL
  const float digitHeight = 0.6 * CUBE_SIZE ;   // Outer rim left for radial dial.
#else
  const float digitHeight = 0.8 * CUBE_SIZE ;   // No space left for radial dial.
#endif

  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  Digit3D_config( this->second100ths_rightDigit
                , CLOCK3D_SECOND100THS_DISPLAYTYPE
                , (R2){ .x = digitWidth            // width
                      , .y = digitHeight           // height
                      }
                , (R2){ .x = digitShift            // shift right
                      , .y = 0.0f
                      }
                , (R3){ .x = DEG_090               // rotationX (vertical)
                      , .y = 0.0f                  // rotationY
                      , .z = 0.0f                  // rotationZ
                      }
                , (R3){ .x = 0.0f
                      , .y =-CUBE_HALF             // positionOfCenter (FAR)
                      , .z = 0.0f
                      }
                ) ;
}


#ifdef CLOCK3D_SECOND100THS_RADIAL
void
Clock3D_second100ths_radial_config
( Clock3D *this )
{
  RadialDial3D_config( this->second100ths_radial
                     , RADIAL_DIAL_SHAPE_SQUARE
                     , RADIAL_INNER_RADIUS       // innerRadius
                     , RADIAL_OUTER_RADIUS       // outerRadius
                     , (R3){ .x = DEG_090        // rotationX (vertical)
                           , .y = 0.0f           // rotationY
                           , .z = 0.0f           // rotationZ
                           }
                     , (R3){ .x = 0.0f           // positionOfCenter (FAR)
                           , .y =-CUBE_HALF
                           , .z = 0.0f
                           }
                     ) ;
}
#endif


void
Clock3D_updateAnimation
( Clock3D  *this
, const int pMaxAnimSteps
)
{
  if ( this->days_leftDigit_animStep > 0
    && this->days_leftDigit_animStep < pMaxAnimSteps
     )
    Clock3D_days_leftDigit_config( this, this->days_leftDigit_animStep++, this->digitType ) ;
  else if (this->days_leftDigit_animStep == pMaxAnimSteps)                                             // Last step of animation ?
  {
    Digit3D_setValue( this->days_leftDigitA, this->days_leftDigitB->value ) ;                          // A side inherits B side value.
    this->days_leftDigitA->mesh->state.isDisabled = this->days_leftDigitB->mesh->state.isDisabled  ;   // A side inherits B side status.
    this->days_leftDigitB->mesh->state.isDisabled = true  ;                                            // Disable B side.
    Clock3D_days_leftDigit_config( this, this->days_leftDigit_animStep = 0, this->digitType ) ;        // Stop flipping this digit.
  }

  if ( this->days_rightDigit_animStep > 0
    && this->days_rightDigit_animStep < pMaxAnimSteps
     )
    Clock3D_days_rightDigit_config( this, this->days_rightDigit_animStep++, this->digitType ) ;
  else if (this->days_rightDigit_animStep == pMaxAnimSteps)                                              // Last step of animation ?
  {
    Digit3D_setValue( this->days_rightDigitA, this->days_rightDigitB->value ) ;                          // A side inherits B side value.
    this->days_rightDigitA->mesh->state.isDisabled = this->days_rightDigitB->mesh->state.isDisabled  ;   // A side inherits B side status.
    this->days_rightDigitB->mesh->state.isDisabled = true  ;                                             // Disable B side.
    Clock3D_days_rightDigit_config( this, this->days_rightDigit_animStep = 0, this->digitType ) ;        // Stop flipping this digit.
  }

  if ( this->hours_leftDigit_animStep > 0
    && this->hours_leftDigit_animStep < pMaxAnimSteps
     )
    Clock3D_hours_leftDigit_config( this, this->hours_leftDigit_animStep++, this->digitType ) ;
  else if (this->hours_leftDigit_animStep == pMaxAnimSteps)                                              // Last step of animation ?
  {
    Digit3D_setValue( this->hours_leftDigitA, this->hours_leftDigitB->value ) ;                          // A side inherits B side value.
    this->hours_leftDigitA->mesh->state.isDisabled = this->hours_leftDigitB->mesh->state.isDisabled  ;   // A side inherits B side status.
    this->hours_leftDigitB->mesh->state.isDisabled = true  ;                                             // Disable B side.
    Clock3D_hours_leftDigit_config( this, this->hours_leftDigit_animStep = 0, this->digitType ) ;        // Stop flipping this digit.
  }

  if ( this->hours_rightDigit_animStep > 0
    && this->hours_rightDigit_animStep < pMaxAnimSteps
     )
    Clock3D_hours_rightDigit_config( this, this->hours_rightDigit_animStep++, this->digitType ) ;
  else if (this->hours_rightDigit_animStep == pMaxAnimSteps)                                          // Last step of animation ?
  {
    Digit3D_setValue( this->hours_rightDigitA, this->hours_rightDigitB->value ) ;                     // A side inherits B side value.
    this->hours_rightDigitB->mesh->state.isDisabled = true  ;                                         // Disable B side.
    Clock3D_hours_rightDigit_config( this, this->hours_rightDigit_animStep = 0, this->digitType ) ;   // Stop flipping this digit.
  }

  if ( this->hours_radial_animStep > 0
    && this->hours_radial_animStep < pMaxAnimSteps
     )
    Clock3D_hours_radial_config( this, this->hours_radial_animStep++ ) ;
  else if (this->hours_radial_animStep == pMaxAnimSteps)                                                // Last step of animation ?
  {
    RadialDial3D_setValue( this->hours_radial, this->hours_radial_valueOnAnimStop ) ;                   // Radial value updated to next value.
    Clock3D_hours_radial_config( this, this->hours_radial_animStep = 0 ) ;                              // Stop animating this radial.
  }

  if ( this->minutes_leftDigit_animStep > 0
    && this->minutes_leftDigit_animStep < pMaxAnimSteps
     )
    Clock3D_minutes_leftDigit_config( this, this->minutes_leftDigit_animStep++, this->digitType ) ;
  else if (this->minutes_leftDigit_animStep == pMaxAnimSteps)                                           // Last step of animation ?
  {
    Digit3D_setValue( this->minutes_leftDigitA, this->minutes_leftDigitB->value ) ;                     // A side inherits B side value.
    this->minutes_leftDigitB->mesh->state.isDisabled = true  ;                                          // Disable B side.
    Clock3D_minutes_leftDigit_config( this, this->minutes_leftDigit_animStep = 0, this->digitType ) ;   // Stop flipping this digit.
  }

  if ( this->minutes_rightDigit_animStep > 0
    && this->minutes_rightDigit_animStep < pMaxAnimSteps
     )
    Clock3D_minutes_rightDigit_config( this, this->minutes_rightDigit_animStep++, this->digitType ) ;
  else if (this->minutes_rightDigit_animStep == pMaxAnimSteps)                                            // Last step of animation ?
  {
    Digit3D_setValue( this->minutes_rightDigitA, this->minutes_rightDigitB->value ) ;                     // A side inherits B side value.
    this->minutes_rightDigitB->mesh->state.isDisabled = true  ;                                           // Disable B side.
    Clock3D_minutes_rightDigit_config( this, this->minutes_rightDigit_animStep = 0, this->digitType ) ;   // Stop flipping this digit.
  }

  if ( this->minutes_radial_animStep > 0
    && this->minutes_radial_animStep < pMaxAnimSteps
     )
    Clock3D_minutes_radial_config( this, this->minutes_radial_animStep++ ) ;
  else if (this->minutes_radial_animStep == pMaxAnimSteps)                                            // Last step of animation ?
  {
    RadialDial3D_setValue( this->minutes_radial, this->minutes_radial_valueOnAnimStop ) ;             // Radial value updated to next value.
    Clock3D_minutes_radial_config( this, this->minutes_radial_animStep = 0 ) ;                        // Stop animating this radial.
  }
}


void
Clock3D_config
( Clock3D           *this
, const Digit2D_Type pDigitType
)
{
  // Config clock's day-of-month 2-digit display meshes.
  Clock3D_days_leftDigit_config ( this, this->days_leftDigit_animStep , pDigitType ) ;
  Clock3D_days_rightDigit_config( this, this->days_rightDigit_animStep, pDigitType ) ;

  // Config clock's hours 2 digits & radial meshes.
  Clock3D_hours_leftDigit_config ( this, this->hours_leftDigit_animStep , pDigitType ) ;
  Clock3D_hours_rightDigit_config( this, this->hours_rightDigit_animStep, pDigitType ) ;
  Clock3D_hours_radial_config    ( this, this->hours_radial_animStep ) ;

  // Config clock's minutes 2 digits & radial meshes.
  Clock3D_minutes_leftDigit_config ( this, this->minutes_leftDigit_animStep , pDigitType ) ;
  Clock3D_minutes_rightDigit_config( this, this->minutes_rightDigit_animStep, pDigitType ) ;
  Clock3D_minutes_radial_config    ( this, this->minutes_radial_animStep ) ;

  // Config clock's seconds 2 digits & radial meshes.
  Clock3D_seconds_leftDigit_config ( this, pDigitType ) ;
  Clock3D_seconds_rightDigit_config( this, pDigitType ) ;
  Clock3D_seconds_radial_config    ( this ) ;

  // Config clock's seconds 100th 2 digits & radial meshes.
  Clock3D_second100ths_leftDigit_config ( this ) ;
  Clock3D_second100ths_rightDigit_config( this ) ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  Clock3D_second100ths_radial_config( this ) ;
#endif
}


void
Clock3D_setDays
( Clock3D      *this
, const uint8_t pDays
)
{
  if (pDays == this->days)
    return ;

  const bool isUninitialized = (this->days == -1) ;
  this->days = pDays ;
  const uint8_t days_leftDigit  = this->days / 10 ;
  const uint8_t days_rightDigit = this->days % 10 ;

  if (isUninitialized)
  {
    Digit3D_setValue( this->days_leftDigitA, days_leftDigit  ) ;
    this->days_leftDigitA->mesh->state.isDisabled = (this->days_leftDigitA->value == 0) ;     // Show A side (if not zero).

    Digit3D_setValue( this->days_leftDigitB, days_leftDigit  ) ;
    this->days_leftDigitB->mesh->state.isDisabled = true ;                                    // Hide B side.

    Digit3D_setValue( this->days_rightDigitA, days_rightDigit ) ;
    this->days_rightDigitA->mesh->state.isDisabled = false ;                                  // Show A side

    Digit3D_setValue( this->days_rightDigitB, days_rightDigit ) ;
    this->days_rightDigitB->mesh->state.isDisabled = true  ;                                  // Hide B side
  }
  else
  {
    if (days_leftDigit != this->days_leftDigitA->value)
    {
      Digit3D_setValue( this->days_leftDigitB, days_leftDigit ) ;                 // Set B side value with new digit value.
      this->days_leftDigitB->mesh->state.isDisabled = (this->days_leftDigitB->value == 0) ;   // Show B side (if not zero).
  
      if (this->days_leftDigit_animStep == 0)   // This digit is not currently flipping ...
        this->days_leftDigit_animStep = 1 ;                                                   // Activate flipping of this digit.
    }

    if (days_rightDigit != this->days_rightDigitA->value)
    {
      Digit3D_setValue( this->days_rightDigitB, days_rightDigit ) ;   // Set B side value with new digit value.
      this->days_rightDigitB->mesh->state.isDisabled = false ;                    // Show B side.
    
      if (this->days_rightDigit_animStep == 0)
        this->days_rightDigit_animStep = 1 ;      // Activate flipping of this digit.
    }
  }

  Clock3D_days_leftDigit_config ( this, this->days_leftDigit_animStep , this->digitType ) ;
  Clock3D_days_rightDigit_config( this, this->days_rightDigit_animStep, this->digitType ) ;
}


void
Clock3D_setHours
( Clock3D      *this
, const uint8_t pHours
)
{
  if (pHours == this->hours)
    return ;

  const bool isUninitialized = (this->hours == -1) ;
  this->hours = pHours ;

  if (clock_is_24h_style( ))
    this->hours_digitsValue = this->hours_radialValue = this->hours ;
  else
  {
    this->hours_digitsValue = this->hours % 12 ;
    this->hours_radialValue  = 2 * this->hours_digitsValue ;

    if (this->hours_digitsValue == 0)
      this->hours_digitsValue = 12 ;
  }

  const uint8_t hours_leftDigit  = this->hours_digitsValue / 10 ;
  const uint8_t hours_rightDigit = this->hours_digitsValue % 10 ;

  if (isUninitialized)
  {
    Digit3D_setValue( this->hours_leftDigitA, hours_leftDigit  ) ;
    this->hours_leftDigitA->mesh->state.isDisabled = (this->hours_leftDigitA->value == 0) ;   // Show A side (if not zero).

    Digit3D_setValue( this->hours_leftDigitB, hours_leftDigit  ) ;
    this->hours_leftDigitB->mesh->state.isDisabled = true ;                                   // Hide B side.

    Digit3D_setValue( this->hours_rightDigitA, hours_rightDigit ) ;
    this->hours_rightDigitA->mesh->state.isDisabled = false ;                                 // Show A side

    Digit3D_setValue( this->hours_rightDigitB, hours_rightDigit ) ;
    this->hours_rightDigitB->mesh->state.isDisabled = true  ;                                 // Hide B side

    RadialDial3D_setValue( this->hours_radial, this->hours_radialValue ) ;
    Clock3D_hours_radial_config( this, this->hours_radial_animStep ) ;
    this->hours_radial->mesh->state.isDisabled = false ;                                      // Show radial
  }
  else
  {
    if (hours_leftDigit != this->hours_leftDigitA->value)
    {
      Digit3D_setValue( this->hours_leftDigitB, hours_leftDigit ) ;                 // Set B side value with new digit value.
      this->hours_leftDigitB->mesh->state.isDisabled = (this->hours_leftDigitB->value == 0) ;   // Show B side (if not zero).

      if (this->hours_leftDigit_animStep == 0)
        this->hours_leftDigit_animStep = 1 ;                                                      // Activate flipping of this digit.
    }

    if (hours_rightDigit != this->hours_rightDigitA->value)
    {
      Digit3D_setValue( this->hours_rightDigitB, hours_rightDigit ) ;   // Set B side value with new digit value.
      this->hours_rightDigitB->mesh->state.isDisabled = false ;                     // Show B side.

      if (this->hours_rightDigit_animStep == 0)
        this->hours_rightDigit_animStep = 1 ;                                         // Activate flipping of this digit.
    }

    if (this->hours == 0)
    {
      this->hours_radial_animStep = 1 ;                                         // Activate midnight hours radial animation.
      this->hours_radial_valueOnAnimStop = this->hours ;
    }
    else
    {
      RadialDial3D_setValue( this->hours_radial, this->hours_radialValue ) ;    // Set hours radial with new value.
      Clock3D_hours_radial_config( this, this->hours_radial_animStep ) ;
    }
  }

  Clock3D_hours_leftDigit_config ( this, this->hours_leftDigit_animStep , this->digitType ) ;
  Clock3D_hours_rightDigit_config( this, this->hours_rightDigit_animStep, this->digitType ) ;
}


void
Clock3D_setMinutes
( Clock3D      *this
, const uint8_t pMinutes
)
{
  if (pMinutes == this->minutes)
      return ;

  const bool isUninitialized = (this->minutes == -1) ;
  this->minutes = pMinutes ;
  const uint8_t minutes_leftDigit  = this->minutes / 10 ;
  const uint8_t minutes_rightDigit = this->minutes % 10 ;

  if (isUninitialized)
  {
    Clock3D_minutes_leftDigit_config( this, this->minutes_leftDigit_animStep, this->digitType  ) ;
    Digit3D_setValue( this->minutes_leftDigitA , minutes_leftDigit  ) ;
    this->minutes_leftDigitA->mesh->state.isDisabled = false ;   // Show A side
    this->minutes_leftDigitB->mesh->state.isDisabled = true  ;   // Hide B side

    Clock3D_minutes_rightDigit_config( this, this->minutes_rightDigit_animStep, this->digitType ) ;
    Digit3D_setValue( this->minutes_rightDigitA, minutes_rightDigit ) ;
    this->minutes_rightDigitA->mesh->state.isDisabled = false ;   // Show A side
    this->minutes_rightDigitB->mesh->state.isDisabled = true  ;   // Hide B side
  
    Clock3D_minutes_radial_config( this, this->minutes_radial_animStep ) ;
    RadialDial3D_setValue( this->minutes_radial, this->minutes ) ;
    this->minutes_radial->mesh->state.isDisabled = false ;       // Show A side

    return ;
  }

  if (minutes_leftDigit != this->minutes_leftDigitA->value)
  {
    Digit3D_setValue( this->minutes_leftDigitB, minutes_leftDigit ) ;   // Set B side value with new digit value.
    this->minutes_leftDigitB->mesh->state.isDisabled = false ;                      // Show B side.

    if (this->minutes_leftDigit_animStep == 0)
      this->minutes_leftDigit_animStep = 1 ;                                          // Activate flipping of this digit.
  }

  if (minutes_rightDigit != this->minutes_rightDigitA->value)
  {
    Digit3D_setValue( this->minutes_rightDigitB, minutes_rightDigit ) ;   // Set B side value with new digit value.
    this->minutes_rightDigitB->mesh->state.isDisabled = false ;                       // Show B side.

    if (this->minutes_rightDigit_animStep == 0)
      this->minutes_rightDigit_animStep = 1 ;                                           // Activate flipping of this digit.
  }

  if (this->minutes == 0)
  {
    this->minutes_radial_valueOnAnimStop = this->minutes ;
    this->minutes_radial_animStep        = 1 ;                       // Activate hour change minutes radial animation.
  }
  else
    RadialDial3D_setValue( this->minutes_radial, this->minutes ) ;   // Set radial value with new value.
}


void
Clock3D_setSeconds
( Clock3D      *this
, const uint8_t pSeconds
)
{
  if (pSeconds == this->seconds)
    return ;

  const bool isUninitialized = (this->seconds == -1) ;
  this->seconds = pSeconds ;
  
  if (isUninitialized)
  {
    // Config clock's seconds 2 digits & radial meshes.
    Clock3D_seconds_leftDigit_config( this, this->digitType ) ;
    this->seconds_leftDigit->mesh->state.isDisabled = false ;

    Clock3D_seconds_rightDigit_config( this, this->digitType ) ;
    this->seconds_rightDigit->mesh->state.isDisabled = false ;

    Clock3D_seconds_radial_config( this ) ;
    this->seconds_radial->mesh->state.isDisabled = false ;
  }

  Digit3D_setValue( this->seconds_leftDigit , this->seconds / 10 ) ;
  Digit3D_setValue( this->seconds_rightDigit, this->seconds % 10 ) ;
  RadialDial3D_setValue       ( this->seconds_radial    , this->seconds      ) ;
}


void
Clock3D_setSecond100ths
( Clock3D      *this
, const uint8_t pSecond100ths
)
{
  if (pSecond100ths == this->second100ths)
    return ;

  const bool isUninitialized = (this->second100ths == -1) ;
  this->second100ths = pSecond100ths ;

  if (isUninitialized)
  {
    Clock3D_second100ths_leftDigit_config( this ) ;
    this->second100ths_leftDigit->mesh->state.isDisabled = false ;

    Clock3D_second100ths_rightDigit_config( this ) ;
    this->second100ths_rightDigit->mesh->state.isDisabled = false ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
    Clock3D_second100ths_radial_config( this ) ;
    this->second100ths_radial->mesh->state.isDisabled = false ;
#endif
  }

  Digit3D_setValue( this->second100ths_leftDigit , this->second100ths / 10 ) ;   // 1/10 th of a second.
  Digit3D_setValue( this->second100ths_rightDigit, this->second100ths % 10 ) ;   // 1/100 th of a second.

#ifdef CLOCK3D_SECOND100THS_RADIAL
  RadialDial3D_setValue( this->second100ths_radial, this->second100ths ) ;
#endif
}


void
Clock3D_second100ths_update
( Clock3D *this )
{
  // Get miliseconds elapsed.
  static uint16_t miliseconds ;
  time_ms( NULL, &miliseconds ) ;
  Clock3D_setSecond100ths( this, miliseconds / 10 ) ;
}


void
Clock3D_setTime_DDHHMMSS
( Clock3D       *this
, const uint8_t  pDays
, const uint8_t  pHours
, const uint8_t  pMinutes
, const uint8_t  pSeconds
)
{
  Clock3D_setDays   ( this, pDays    ) ;
  Clock3D_setHours  ( this, pHours   ) ;
  Clock3D_setMinutes( this, pMinutes ) ;
  Clock3D_setSeconds( this, pSeconds ) ;
}


void
Clock3D_updateDDHHMMSS
( Clock3D *this )
{
  time_t now ;
  time( &now ) ;
  const struct tm *now_tm = localtime( &now ) ;

  Clock3D_setTime_DDHHMMSS( this
                          , now_tm->tm_mday   // days
                          , now_tm->tm_hour   // hours
                          , now_tm->tm_min    // minutes
                          , now_tm->tm_sec    // seconds
                          ) ;
}


void
Clock3D_draw
( GContext               *gCtx
, Clock3D                *this
, const CamR3            *cam
, const int               w
, const int               h
, const MeshTransparency  transparency
)
{
  MeshR3_draw( gCtx, this->cube, cam, w, h, Clock3D_isAnimated( this ) ? MESH_TRANSPARENCY_XRAY : transparency ) ;

  MeshR3_draw( gCtx, this->days_leftDigitB ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->days_leftDigitA ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->days_rightDigitB->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->days_rightDigitA->mesh, cam, w, h, transparency ) ;

  MeshR3_draw( gCtx, this->hours_leftDigitB ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->hours_leftDigitA ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->hours_rightDigitB->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->hours_rightDigitA->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->hours_radial     ->mesh, cam, w, h, transparency ) ;

  MeshR3_draw( gCtx, this->minutes_leftDigitB ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->minutes_leftDigitA ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->minutes_rightDigitB->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->minutes_rightDigitA->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->minutes_radial     ->mesh, cam, w, h, transparency ) ;

  MeshR3_draw( gCtx, this->seconds_leftDigit ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->seconds_rightDigit->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->seconds_radial    ->mesh, cam, w, h, transparency ) ;

  MeshR3_draw( gCtx, this->second100ths_leftDigit ->mesh, cam, w, h, transparency ) ;
  MeshR3_draw( gCtx, this->second100ths_rightDigit->mesh, cam, w, h, transparency ) ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  MeshR3_draw( gCtx, this->second100ths_radial->mesh, cam, w, h, transparency ) ;
#endif
}