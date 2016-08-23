/*
   Package: Clock3D
   File   : Clock3D.c
   Author : Afonso Santos, Portugal

   Last revision: 09h10 August 22 2016
*/

#include <pebble.h>
#include "FastMath.h"
#include "Clock3D.h"


// Between the cube, the segment displays and the radial dials the biggest mesh has no more than 200 vertices.
GPoint __Mesh3D_vertex_screenPoint[200] ;

// Externaly provided interpolation tables.
extern float     *spinRotationFraction    ;
extern float     *animRotationFraction    ;
extern float     *animTranslationFraction ;


Digit2D_Type   clock_displayType = CLOCK3D_DISPLAY_TYPE_DEFAULT ;

Mesh3D        *clock_cube ;

static int8_t  clock_days              = -1 ;  // Initialy undefined.
Digit3D       *clock_days_leftDigitA ;
Digit3D       *clock_days_leftDigitB ;
Digit3D       *clock_days_rightDigitA ;
Digit3D       *clock_days_rightDigitB ;

static int8_t  clock_hours             = -1 ;  // Initialy undefined.
static int8_t  clock_hours_digitsValue = -1 ;  // Initialy undefined.
static int8_t  clock_hours_radialValue = -1 ;  // Initialy undefined.
Digit3D       *clock_hours_leftDigitA ;
Digit3D       *clock_hours_leftDigitB ;
Digit3D       *clock_hours_rightDigitA ;
Digit3D       *clock_hours_rightDigitB ;
RadialDial3D  *clock_hours_radial ;
unsigned int   clock_hours_radial_valueOnAnimStop ;

static int8_t  clock_minutes           = -1 ;  // Initialy undefined.
Digit3D       *clock_minutes_leftDigitA ;
Digit3D       *clock_minutes_leftDigitB ;
Digit3D       *clock_minutes_rightDigitA ;
Digit3D       *clock_minutes_rightDigitB ;
RadialDial3D  *clock_minutes_radial ;
unsigned int   clock_minutes_radial_valueOnAnimStop ;

static int8_t  clock_seconds           = -1 ;  // Initialy undefined.
Digit3D       *clock_seconds_leftDigit ;
Digit3D       *clock_seconds_rightDigit ;
RadialDial3D  *clock_seconds_radial ;

static int8_t  clock_second100ths      = -1 ;  // Initialy undefined.
Digit3D       *clock_second100ths_leftDigit ;
Digit3D       *clock_second100ths_rightDigit ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
RadialDial3D  *clock_second100ths_radial ;
#endif


// Clock initialization.
void
Clock3D_initialize
( )
{
  // ***  Allocate meshes  ***

  // Instantiate cube mesh.
  Cube_config( clock_cube = Cube_new( )
             , CUBE_SIZE               // sideLenght
             , NULL                    // inkBlinker
             ) ;

  // Instantiate DD, HH, MM, SS, 100th clock value displays.
  clock_days_leftDigitA         = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_days_leftDigitB         = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_days_rightDigitA        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_days_rightDigitB        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;

  clock_hours_leftDigitA        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_hours_leftDigitB        = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_hours_rightDigitA       = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_hours_rightDigitB       = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_hours_radial            = RadialDial3D_new( RADIAL_DIAL_TYPE_24 ) ;

  clock_minutes_leftDigitA      = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_minutes_leftDigitB      = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_minutes_rightDigitA     = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_minutes_rightDigitB     = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_minutes_radial          = RadialDial3D_new( RADIAL_DIAL_TYPE_60 ) ;

  clock_seconds_leftDigit       = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_seconds_rightDigit      = Digit3D_new( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
  clock_seconds_radial          = RadialDial3D_new( RADIAL_DIAL_TYPE_60 ) ;

  clock_second100ths_leftDigit  = Digit3D_new( CLOCK3D_SECOND100THS_DISPLAYTYPE_MAJOR ) ;
  clock_second100ths_rightDigit = Digit3D_new( CLOCK3D_SECOND100THS_DISPLAYTYPE_MAJOR ) ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  clock_second100ths_radial     = RadialDial3D_new( RADIAL_DIAL_TYPE_100 ) ;
#endif

  // ***  Configure stroke properties  ***

  // days
  clock_days_leftDigitA ->mesh->strokeColor =
  clock_days_leftDigitB ->mesh->strokeColor =
  clock_days_rightDigitA->mesh->strokeColor =
  clock_days_rightDigitB->mesh->strokeColor = GColorYellow
  ;

  // hours
  clock_hours_leftDigitA ->mesh->strokeColor =
  clock_hours_leftDigitB ->mesh->strokeColor =
  clock_hours_rightDigitA->mesh->strokeColor =
  clock_hours_rightDigitB->mesh->strokeColor =
  clock_hours_radial     ->mesh->strokeColor = GColorGreen
  ;
  clock_hours_radial->mesh->edgeAlternateMask_L2R = RADIAL_DIAL_24_EVERY6ALTERNATEEDGEMASK_L2R ;

  clock_hours_radial->mesh->strokeWidthAlternate = 2 ;
  clock_hours_radial->mesh->strokeColorAlternate = clock_hours_radial->mesh->strokeColor ;

  // minutes
  clock_minutes_leftDigitA ->mesh->strokeColor =
  clock_minutes_leftDigitB ->mesh->strokeColor =
  clock_minutes_rightDigitA->mesh->strokeColor =
  clock_minutes_rightDigitB->mesh->strokeColor =
  clock_minutes_radial     ->mesh->strokeColor = GColorRed
  ;
  clock_minutes_radial->mesh->edgeAlternateMask_L2R = RADIAL_DIAL_60_EVERY5ALTERNATEEDGEMASK_L2R ;

  clock_minutes_radial->mesh->strokeWidthAlternate = 2 ;
  clock_minutes_radial->mesh->strokeColorAlternate = clock_minutes_radial->mesh->strokeColor ;

  // seconds
  clock_seconds_leftDigit ->mesh->strokeColor =
  clock_seconds_rightDigit->mesh->strokeColor =
  clock_seconds_radial    ->mesh->strokeColor = GColorVividCerulean
  ;

  clock_seconds_radial->mesh->edgeAlternateMask_L2R = RADIAL_DIAL_60_EVERY5ALTERNATEEDGEMASK_L2R ;

  clock_seconds_radial->mesh->strokeWidthAlternate = 2 ;
  clock_seconds_radial->mesh->strokeColorAlternate = clock_seconds_radial->mesh->strokeColor ;

  // second100ths
  clock_second100ths_leftDigit ->mesh->strokeColor          =                                 // Left digit skin color.
  clock_second100ths_rightDigit->mesh->strokeColorAlternate =
  clock_second100ths_rightDigit->mesh->strokeColor          = GColorRichBrilliantLavender ;   // Right digit skin color.
  clock_second100ths_leftDigit ->mesh->strokeColorAlternate = GColorRed ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  clock_second100ths_radial->mesh->strokeColor = clock_second100ths_rightDigit->mesh->strokeColor ;
  clock_second100ths_radial->mesh->edgeAlternateMask_L2R  = RADIAL_DIAL_100_EVERY10ALTERNATEEDGEMASK_L2R ;
  clock_second100ths_radial->mesh->strokeWidthAlternate = 2 ;

  clock_second100ths_radial->mesh->strokeColorAlternate = clock_second100ths_leftDigit->mesh->strokeColorAlternate ;

#endif
}


void
Clock3D_finalize
( )
{
  free( Mesh3D_free          ( clock_cube                ) )     ; clock_cube                    = NULL ;

  free( Digit3D_free( clock_days_leftDigitB     ) )     ; clock_days_leftDigitB         = NULL ;
  free( Digit3D_free( clock_days_leftDigitA     ) )     ; clock_days_leftDigitA         = NULL ;
  free( Digit3D_free( clock_days_rightDigitB    ) )     ; clock_days_rightDigitB        = NULL ;
  free( Digit3D_free( clock_days_rightDigitA    ) )     ; clock_days_rightDigitA        = NULL ;

  free( Digit3D_free( clock_hours_leftDigitB    ) )     ; clock_hours_leftDigitB        = NULL ;
  free( Digit3D_free( clock_hours_leftDigitA    ) )     ; clock_hours_leftDigitA        = NULL ;
  free( Digit3D_free( clock_hours_rightDigitB   ) )     ; clock_hours_rightDigitB       = NULL ;
  free( Digit3D_free( clock_hours_rightDigitA   ) )     ; clock_hours_rightDigitA       = NULL ;
  free( RadialDial3D_free( clock_hours_radial        ) )     ; clock_hours_radial            = NULL ;

  free( Digit3D_free( clock_minutes_leftDigitB  ) )     ; clock_minutes_leftDigitB      = NULL ;
  free( Digit3D_free( clock_minutes_leftDigitA  ) )     ; clock_minutes_leftDigitA      = NULL ;
  free( Digit3D_free( clock_minutes_rightDigitB ) )     ; clock_minutes_rightDigitB     = NULL ;
  free( Digit3D_free( clock_minutes_rightDigitA ) )     ; clock_minutes_rightDigitA     = NULL ;
  free( RadialDial3D_free( clock_minutes_radial      ) )     ; clock_minutes_radial          = NULL ;

  free( Digit3D_free( clock_seconds_leftDigit   ) )     ; clock_seconds_leftDigit       = NULL ;
  free( Digit3D_free( clock_seconds_rightDigit  ) )     ; clock_seconds_rightDigit      = NULL ;
  free( RadialDial3D_free( clock_seconds_radial      ) )     ; clock_seconds_radial          = NULL ;

  free( Digit3D_free( clock_second100ths_leftDigit  ) ) ; clock_second100ths_leftDigit  = NULL ;
  free( Digit3D_free( clock_second100ths_rightDigit ) ) ; clock_second100ths_rightDigit = NULL ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  free( RadialDial3D_free( clock_second100ths_radial     ) ) ; clock_second100ths_radial     = NULL ;
#endif
}


// Clock configuration.

void
Clock3D_days_leftDigit_config
( const int          pAnimStep
, const Digit2D_Type pDisplayType
)
{
  const float digitHeight = 0.8 * CUBE_SIZE ;
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap ) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( clock_days_leftDigitA
                , pDisplayType
                , digitWidth                               // width
                , digitHeight                              // height
                , -digitShift                              // shift left
                , 0.0                                      // rotationX (face FRONT)
                , animRotation                             // rotationY
                , DEG_090                                  // rotationZ
                , &(R3){ .x = 0                            // positionOfCenter (TOP)
                       , .y = 0
                       , .z = CUBE_HALF + animTranslation
                       }
                ) ;

  Digit3D_config( clock_days_leftDigitB
                , pDisplayType
                , digitWidth                               // width
                , digitHeight                              // height
                , -digitShift                              // shift left
                , 0.0                                      // rotationX (face FRONT)
                , DEG_180 + animRotation                   // rotationY
                , DEG_090                                  // rotationZ
                , &(R3){ .x = 0.0                          // positionOfCenter (TOP)
                       , .y = 0.0
                       , .z = CUBE_HALF + animTranslation
                       }
                ) ;
}

void
Clock3D_days_rightDigit_config
( const int          pAnimStep
, const Digit2D_Type pDisplayType
)
{
  const float digitHeight = 0.8 * CUBE_SIZE ;
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap ) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  const float rightDigitA_valueShift = clock_days_leftDigitA->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( clock_days_rightDigitA
                         , pDisplayType
                         , digitWidth                               // width
                         , digitHeight                              // height
                         , rightDigitA_valueShift                   // shift right
                         , 0.0                                      // rotationX (face FRONT)
                         , animRotation                             // rotationY
                         , DEG_090                                  // rotationZ
                         , &(R3){ .x = 0.0                          // positionOfCenter (TOP)
                                , .y = 0.0
                                , .z = CUBE_HALF + animTranslation
                                }
                         ) ;

  const float rightDigitB_valueShift = clock_days_leftDigitB->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( clock_days_rightDigitB
                         , clock_displayType
                         , digitWidth                               // width
                         , digitHeight                              // height
                         , rightDigitB_valueShift                   // shift right
                         , 0.0                                      // rotationX (face FRONT)
                         , DEG_180 + animRotation                   // rotationY
                         , DEG_090                                  // rotationZ
                         , &(R3){ .x = 0.0                          // positionOfCenter (TOP)
                                , .y = 0.0
                                , .z = CUBE_HALF + animTranslation
                                }
                         ) ;
}


void
Clock3D_hours_leftDigit_config
( const int          pAnimStep
, const Digit2D_Type pDisplayType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( clock_hours_leftDigitA
                         , pDisplayType
                         , digitWidth                                // width
                         , digitHeight                               // height
                         ,-digitShift                                // shift left
                         , DEG_180                                   // rotationX
                         , DEG_270 + animRotation                    // rotationY
                         , DEG_270                                   // rotationZ
                         , &(R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                                , .y = 0.0
                                , .z = 0.0
                                }
                         ) ;

  Digit3D_config( clock_hours_leftDigitB
                         , pDisplayType
                         , digitWidth                                // width
                         , digitHeight                               // height
                         ,-digitShift                                // shift left
                         , DEG_180                                   // rotationX
                         , DEG_090 + animRotation                    // rotationY
                         , DEG_270                                   // rotationZ
                         , &(R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                                , .y = 0.0
                                , .z = 0.0
                                }
                         ) ;
}


void
Clock3D_hours_rightDigit_config
( const int          pAnimStep
, const Digit2D_Type pDisplayType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  const float rightDigitA_valueShift = clock_hours_leftDigitA->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( clock_hours_rightDigitA
                         , pDisplayType
                         , digitWidth                                // width
                         , digitHeight                               // height
                         , rightDigitA_valueShift                    // shift left
                         , DEG_180                                   // rotationX
                         , DEG_270 + animRotation                    // rotationY
                         , DEG_270                                   // rotationZ
                         , &(R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                                , .y = 0.0
                                , .z = 0.0
                                }
                         ) ;

  const float rightDigitB_valueShift = clock_hours_leftDigitB->value > 0 ? digitShift : 0.0 ;

  Digit3D_config( clock_hours_rightDigitB
                         , pDisplayType
                         , digitWidth                                // width
                         , digitHeight                               // height
                         , rightDigitB_valueShift                    // shift left
                         , DEG_180                                   // rotationX
                         , DEG_090 + animRotation                    // rotationY
                         , DEG_270                                   // rotationZ
                         , &(R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                                , .y = 0.0
                                , .z = 0.0
                                }
                         ) ;
}


void
Clock3D_hours_radial_config
( const int pAnimStep )
{
  const float digitHeight     = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  RadialDial3D_config( clock_hours_radial
                     , clock_hours_digitsValue > 9  ?  RADIAL_DIAL_SHAPE_SQUARE  : RADIAL_DIAL_SHAPE_CIRCLE
                     , RADIAL_INNER_RADIUS       // innerRadius
                     , RADIAL_OUTER_RADIUS       // outerRadius
                     , DEG_180                   // rotationX
                     , DEG_270                   // rotationY
                     , DEG_270                   // rotationZ
                     , &(R3){ .x = CUBE_HALF + animTranslation   // positionOfCenter (LEFT face, left shifted)
                            , .y = 0.0
                            , .z = 0.0
                            }
                     ) ;
}


void
Clock3D_minutes_leftDigit_config
( const int          pAnimStep
, const Digit2D_Type pDisplayType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( clock_minutes_leftDigitA
                         , pDisplayType
                         , digitWidth                                // width
                         , digitHeight                               // height
                         ,-digitShift                                // shift left
                         ,-DEG_090 + animRotation                    // rotationX (face FRONT)
                         , DEG_180                                   // rotationY (mirror turn)
                         , 0.0                                       // rotationZ
                         , &(R3){ .x = 0                             // positionOfCenter (NEAR)
                                , .y = CUBE_HALF + animTranslation
                                , .z = 0
                                }
                         ) ;

  Digit3D_config( clock_minutes_leftDigitB
                         , pDisplayType
                         , digitWidth                                // width
                         , digitHeight                               // height
                         ,-digitShift                                // shift left
                         , DEG_090 + animRotation                    // rotationX (face FRONT)
                         , DEG_180                                   // rotationY (mirror turn)
                         , 0.0                                       // rotationZ
                         , &(R3){ .x = 0.0                           // positionOfCenter (NEAR)
                                , .y = CUBE_HALF + animTranslation
                                , .z = 0.0
                                }
                         ) ;
}


void
Clock3D_minutes_rightDigit_config
( const int          pAnimStep
, const Digit2D_Type pDisplayType
)
{
  const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;
  
  const float animRotation    = DEG_180           * animRotationFraction[pAnimStep] ;
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  Digit3D_config( clock_minutes_rightDigitA
                         , pDisplayType
                         , digitWidth                                               // width
                         , digitHeight                                              // height
                         , digitShift                                               // shift right
                         ,-DEG_090 + animRotation                                   // rotationX (face FRONT)
                         , DEG_180                                                  // rotationY (mirror turn)
                         , 0.0                                                      // rotationZ
                         , &(R3){ .x = 0                                            // positionOfCenter (NEAR)
                                , .y = CUBE_HALF + animTranslation
                                , .z = 0
                                }
                         ) ;

  Digit3D_config( clock_minutes_rightDigitB
                         , pDisplayType
                         , digitWidth                                               // width
                         , digitHeight                                              // height
                         , digitShift                                               // shift right
                         , DEG_090 + animRotation                                   // rotationX (face FRONT)
                         , DEG_180                                                  // rotationY (mirror turn)
                         , 0.0                                                      // rotationZ
                         , &(R3){ .x = 0.0                                          // positionOfCenter (NEAR)
                                , .y = CUBE_HALF + animTranslation
                                , .z = 0.0
                                }
                         ) ;
}


void
Clock3D_minutes_radial_config
( const int pAnimStep )
{
  const float digitHeight     = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
  const float animTranslation = 0.3 * digitHeight * animTranslationFraction[pAnimStep] ;

  RadialDial3D_config( clock_minutes_radial
                     , RADIAL_DIAL_SHAPE_SQUARE
                     , RADIAL_INNER_RADIUS       // innerRadius
                     , RADIAL_OUTER_RADIUS       // outerRadius
                     ,-DEG_090                   // rotationX (face FRONT)
                     , DEG_180                               // rotationY (mirror turn)
                     , 0.0                                   // rotationZ
                     , &(R3){ .x = 0.0                       // positionOfCenter (NEAR)
                            , .y = CUBE_HALF + animTranslation
                            , .z = 0.0
                            }
                     ) ;
}


void
Clock3D_seconds_leftDigit_config
( const Digit2D_Type pDisplayType )
{
    const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
    const float digitGap    = 0.1 * CUBE_SIZE ;
    const float digitWidth  = (digitHeight - digitGap) / 2 ;
    const float digitShift  = (digitWidth + digitGap) / 2 ;
    
    Digit3D_config( clock_seconds_leftDigit
                           , pDisplayType
                           , digitWidth                        // width
                           , digitHeight                       // height
                           ,-digitShift                        // shift left
                           , DEG_180                           // rotationX
                           , DEG_090                           // rotationY
                           , DEG_090                           // rotationZ
                           , &(R3){ .x = -CUBE_HALF            // positionOfCenter (RIGHT)
                                  , .y = 0
                                  , .z = 0
                                  }
                           ) ;
}


void
Clock3D_seconds_rightDigit_config
( const Digit2D_Type pDisplayType )
{
    const float digitHeight = 0.6 * CUBE_SIZE ;    // Outer rim left for radial dials.
    const float digitGap    = 0.1 * CUBE_SIZE ;
    const float digitWidth  = (digitHeight - digitGap) / 2 ;
    const float digitShift  = (digitWidth + digitGap) / 2 ;
    
    Digit3D_config( clock_seconds_rightDigit
                           , pDisplayType
                           , digitWidth                        // width
                           , digitHeight                       // height
                           , digitShift                        // shift right
                           , DEG_180                           // rotationX
                           , DEG_090                           // rotationY
                           , DEG_090                           // rotationZ
                           , &(R3){ .x = -CUBE_HALF            // positionOfCenter (RIGHT)
                                  , .y = 0
                                  , .z = 0 
                                  }
                           ) ;
}


void
Clock3D_seconds_radial_config
( )
{
  RadialDial3D_config( clock_seconds_radial
                     , RADIAL_DIAL_SHAPE_SQUARE
                     , RADIAL_INNER_RADIUS       // innerRadius
                     , RADIAL_OUTER_RADIUS       // outerRadius
                     , DEG_180                   // rotationX
                     , DEG_090                   // rotationY
                     , DEG_090                   // rotationZ
                     , &(R3){ .x = -CUBE_HALF    // positionOfCenter (RIGHT)
                            , .y = 0.0
                            , .z = 0.0
                            }
                     ) ;
}


void
Clock3D_second100ths_leftDigit_config
( )
{
#ifdef CLOCK3D_SECOND100THS_RADIAL
  const float digitHeight = 0.6 * CUBE_SIZE ;   // Outer rim left for radial dial.
#else
  const float digitHeight = 0.8 * CUBE_SIZE ;   // No space left for radial dial.
#endif

  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  Digit3D_config( clock_second100ths_leftDigit
                         , CLOCK3D_SECOND100THS_DISPLAYTYPE
                         , digitWidth                        // width
                         , digitHeight                       // height
                         ,-digitShift                        // shift left
                         , DEG_090                           // rotationX (vertical)
                         , 0.0                               // rotationY
                         , 0.0                               // rotationZ
                         , &(R3){ .x = 0.0                   // positionOfCenter (FAR)
                                , .y = -CUBE_HALF
                                , .z = 0.0
                                }
                         ) ;
}


void
Clock3D_second100ths_rightDigit_config
( )
{
#ifdef CLOCK3D_SECOND100THS_RADIAL
  const float digitHeight = 0.6 * CUBE_SIZE ;   // Outer rim left for radial dial.
#else
  const float digitHeight = 0.8 * CUBE_SIZE ;   // No space left for radial dial.
#endif

  const float digitGap    = 0.1 * CUBE_SIZE ;
  const float digitWidth  = (digitHeight - digitGap) / 2 ;
  const float digitShift  = (digitWidth + digitGap) / 2 ;

  Digit3D_config( clock_second100ths_rightDigit
                         , CLOCK3D_SECOND100THS_DISPLAYTYPE
                         , digitWidth                        // width
                         , digitHeight                       // height
                         , digitShift                        // shift right
                         , DEG_090                           // rotationX (vertical)
                         , 0.0                               // rotationY
                         , 0.0                               // rotationZ
                         , &(R3){ .x = 0.0                   // positionOfCenter (FAR)
                                , .y = -CUBE_HALF
                                , .z = 0.0
                                }
                         ) ;
}


#ifdef CLOCK3D_SECOND100THS_RADIAL
void
Clock3D_second100ths_radial_config
( )
{
  RadialDial3D_config( clock_second100ths_radial
                     , RADIAL_DIAL_SHAPE_SQUARE
                     , RADIAL_INNER_RADIUS       // innerRadius
                     , RADIAL_OUTER_RADIUS       // outerRadius
                     , DEG_090                   // rotationX (vertical)
                     , 0.0                       // rotationY
                     , 0.0                       // rotationZ
                     , &(R3){ .x = 0.0           // positionOfCenter (FAR)
                            , .y = -CUBE_HALF
                            , .z = 0.0
                            }
                     ) ;
}
#endif


int    clock_days_leftDigit_animStep     = 0 ;    // Initially idle
int    clock_days_rightDigit_animStep    = 0 ;    // Initially idle
int    clock_hours_leftDigit_animStep    = 0 ;    // Initially idle
int    clock_hours_rightDigit_animStep   = 0 ;    // Initially idle
int    clock_hours_radial_animStep       = 0 ;    // Initially idle
int    clock_minutes_leftDigit_animStep  = 0 ;    // Initially idle
int    clock_minutes_rightDigit_animStep = 0 ;    // Initially idle
int    clock_minutes_radial_animStep     = 0 ;    // Initially idle


void
Clock3D_updateAnimation
( const int pMaxAnimSteps )
{
  if ( clock_days_leftDigit_animStep > 0
    && clock_days_leftDigit_animStep < pMaxAnimSteps
     )
    Clock3D_days_leftDigit_config( clock_days_leftDigit_animStep++, clock_displayType ) ;
  else if (clock_days_leftDigit_animStep == pMaxAnimSteps)                                             // Last step of animation ?
  {
    Digit3D_setValue( clock_days_leftDigitA, clock_days_leftDigitB->value ) ;              // A side inherits B side value.
    clock_days_leftDigitA->mesh->state.isDisabled = clock_days_leftDigitB->mesh->state.isDisabled  ;   // A side inherits B side status.
    clock_days_leftDigitB->mesh->state.isDisabled = true  ;                                            // Disable B side.
    Clock3D_days_leftDigit_config( clock_days_leftDigit_animStep = 0, clock_displayType ) ;            // Stop flipping this digit.
  }

  if ( clock_days_rightDigit_animStep > 0
    && clock_days_rightDigit_animStep < pMaxAnimSteps
     )
    Clock3D_days_rightDigit_config( clock_days_rightDigit_animStep++, clock_displayType ) ;
  else if (clock_days_rightDigit_animStep == pMaxAnimSteps)                                              // Last step of animation ?
  {
    Digit3D_setValue( clock_days_rightDigitA, clock_days_rightDigitB->value ) ;              // A side inherits B side value.
    clock_days_rightDigitA->mesh->state.isDisabled = clock_days_rightDigitB->mesh->state.isDisabled  ;   // A side inherits B side status.
    clock_days_rightDigitB->mesh->state.isDisabled = true  ;                                             // Disable B side.
    Clock3D_days_rightDigit_config( clock_days_rightDigit_animStep = 0, clock_displayType ) ;            // Stop flipping this digit.
  }

  if ( clock_hours_leftDigit_animStep > 0
    && clock_hours_leftDigit_animStep < pMaxAnimSteps
     )
    Clock3D_hours_leftDigit_config( clock_hours_leftDigit_animStep++, clock_displayType ) ;
  else if (clock_hours_leftDigit_animStep == pMaxAnimSteps)                                              // Last step of animation ?
  {
    Digit3D_setValue( clock_hours_leftDigitA, clock_hours_leftDigitB->value ) ;              // A side inherits B side value.
    clock_hours_leftDigitA->mesh->state.isDisabled = clock_hours_leftDigitB->mesh->state.isDisabled  ;   // A side inherits B side status.
    clock_hours_leftDigitB->mesh->state.isDisabled = true  ;                                             // Disable B side.
    Clock3D_hours_leftDigit_config( clock_hours_leftDigit_animStep = 0, clock_displayType ) ;            // Stop flipping this digit.
  }

  if ( clock_hours_rightDigit_animStep > 0
    && clock_hours_rightDigit_animStep < pMaxAnimSteps
     )
    Clock3D_hours_rightDigit_config( clock_hours_rightDigit_animStep++, clock_displayType ) ;
  else if (clock_hours_rightDigit_animStep == pMaxAnimSteps)                                      // Last step of animation ?
  {
    Digit3D_setValue( clock_hours_rightDigitA, clock_hours_rightDigitB->value ) ;     // A side inherits B side value.
    clock_hours_rightDigitB->mesh->state.isDisabled = true  ;                                     // Disable B side.
    Clock3D_hours_rightDigit_config( clock_hours_rightDigit_animStep = 0, clock_displayType ) ;   // Stop flipping this digit.
  }

  if ( clock_hours_radial_animStep > 0
    && clock_hours_radial_animStep < pMaxAnimSteps
     )
    Clock3D_hours_radial_config( clock_hours_radial_animStep++ ) ;
  else if (clock_hours_radial_animStep == pMaxAnimSteps)                                          // Last step of animation ?
  {
    RadialDial3D_setValue( clock_hours_radial, clock_hours_radial_valueOnAnimStop ) ;             // Radial value updated to next value.
    Clock3D_hours_radial_config( clock_hours_radial_animStep = 0 ) ;                              // Stop animating this radial.
  }

  if ( clock_minutes_leftDigit_animStep > 0
    && clock_minutes_leftDigit_animStep < pMaxAnimSteps
     )
    Clock3D_minutes_leftDigit_config( clock_minutes_leftDigit_animStep++, clock_displayType ) ;
  else if (clock_minutes_leftDigit_animStep == pMaxAnimSteps)                                       // Last step of animation ?
  {
    Digit3D_setValue( clock_minutes_leftDigitA, clock_minutes_leftDigitB->value ) ;     // A side inherits B side value.
    clock_minutes_leftDigitB->mesh->state.isDisabled = true  ;                                      // Disable B side.
    Clock3D_minutes_leftDigit_config( clock_minutes_leftDigit_animStep = 0, clock_displayType ) ;   // Stop flipping this digit.
  }

  if ( clock_minutes_rightDigit_animStep > 0
    && clock_minutes_rightDigit_animStep < pMaxAnimSteps
     )
    Clock3D_minutes_rightDigit_config( clock_minutes_rightDigit_animStep++, clock_displayType ) ;
  else if (clock_minutes_rightDigit_animStep == pMaxAnimSteps)            // Last step of animation ?
  {
    Digit3D_setValue( clock_minutes_rightDigitA, clock_minutes_rightDigitB->value ) ;     // A side inherits B side value.
    clock_minutes_rightDigitB->mesh->state.isDisabled = true  ;                                       // Disable B side.
    Clock3D_minutes_rightDigit_config( clock_minutes_rightDigit_animStep = 0, clock_displayType ) ;   // Stop flipping this digit.
  }

  if ( clock_minutes_radial_animStep > 0
    && clock_minutes_radial_animStep < pMaxAnimSteps
     )
    Clock3D_minutes_radial_config( clock_minutes_radial_animStep++ ) ;
  else if (clock_minutes_radial_animStep == pMaxAnimSteps)                                            // Last step of animation ?
  {
    RadialDial3D_setValue( clock_minutes_radial, clock_minutes_radial_valueOnAnimStop ) ;             // Radial value updated to next value.
    Clock3D_minutes_radial_config( clock_minutes_radial_animStep = 0 ) ;                              // Stop animating this radial.
  }
}


bool
Clock3D_isAnimated
( )
{
  return clock_days_leftDigit_animStep > 0
      || clock_days_rightDigit_animStep > 0
      || clock_hours_leftDigit_animStep > 0
      || clock_hours_rightDigit_animStep > 0
      || clock_hours_radial_animStep > 0
      || clock_minutes_leftDigit_animStep > 0
      || clock_minutes_rightDigit_animStep > 0
      || clock_minutes_radial_animStep > 0
       ;
}


void
Clock3D_animateAllDigits
( )
{
  if (clock_days_leftDigit_animStep == 0)
  {
    Digit3D_setValue( clock_days_leftDigitB, clock_days_leftDigitA->value ) ;              // B side inherits A side value.
    clock_days_leftDigitB->mesh->state.isDisabled = clock_days_leftDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    clock_days_leftDigit_animStep = 1 ;
  }

  if (clock_days_rightDigit_animStep == 0)
  {
    Digit3D_setValue( clock_days_rightDigitB, clock_days_rightDigitA->value ) ;              // B side inherits A side value.
    clock_days_rightDigitB->mesh->state.isDisabled = clock_days_rightDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    clock_days_rightDigit_animStep = 1 ;
  }

  if (clock_hours_leftDigit_animStep == 0)
  {
    Digit3D_setValue( clock_hours_leftDigitB, clock_hours_leftDigitA->value ) ;              // B side inherits A side value.
    clock_hours_leftDigitB->mesh->state.isDisabled = clock_hours_leftDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    clock_hours_leftDigit_animStep = 1 ;
  }

  if (clock_hours_rightDigit_animStep == 0)
  {
    Digit3D_setValue( clock_hours_rightDigitB, clock_hours_rightDigitA->value ) ;              // B side inherits A side value.
    clock_hours_rightDigitB->mesh->state.isDisabled = clock_hours_rightDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    clock_hours_rightDigit_animStep = 1 ;
  }

  if (clock_minutes_leftDigit_animStep == 0)
  {
    Digit3D_setValue( clock_minutes_leftDigitB, clock_minutes_leftDigitA->value ) ;              // B side inherits A side value.
    clock_minutes_leftDigitB->mesh->state.isDisabled = clock_minutes_leftDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    clock_minutes_leftDigit_animStep = 1 ;
  }

  if (clock_minutes_rightDigit_animStep == 0)
  {
    Digit3D_setValue( clock_minutes_rightDigitB, clock_minutes_rightDigitA->value ) ;              // B side inherits A side value.
    clock_minutes_rightDigitB->mesh->state.isDisabled = clock_minutes_rightDigitA->mesh->state.isDisabled  ;   // B side inherits A side status.
    clock_minutes_rightDigit_animStep = 1 ;
  }
}


void
Clock3D_animateAllRadials
( )
{
  if (clock_minutes_radial_animStep == 0)
  {
    clock_minutes_radial_valueOnAnimStop = clock_minutes_radial->value ;
    clock_minutes_radial_animStep        = 1 ;
  }

  if (clock_hours_radial_animStep == 0)
  {
    clock_hours_radial_valueOnAnimStop = clock_hours_radial->value ;
    clock_hours_radial_animStep        = 1 ;
  }
}


void
Clock3D_animateAll
( )
{
  Clock3D_animateAllDigits( ) ;
  Clock3D_animateAllRadials( ) ;
}


void
Clock3D_config
( const Digit2D_Type pDisplayType )
{
  // Config clock's day-of-month 2-digit display meshes.
  Clock3D_days_leftDigit_config ( clock_days_leftDigit_animStep , pDisplayType ) ;
  Clock3D_days_rightDigit_config( clock_days_rightDigit_animStep, pDisplayType ) ;

  // Config clock's hours 2 digits & radial meshes.
  Clock3D_hours_leftDigit_config ( clock_hours_leftDigit_animStep , pDisplayType ) ;
  Clock3D_hours_rightDigit_config( clock_hours_rightDigit_animStep, pDisplayType ) ;
  Clock3D_hours_radial_config    ( clock_hours_radial_animStep ) ;

  // Config clock's minutes 2 digits & radial meshes.
  Clock3D_minutes_leftDigit_config ( clock_minutes_leftDigit_animStep , pDisplayType ) ;
  Clock3D_minutes_rightDigit_config( clock_minutes_rightDigit_animStep, pDisplayType ) ;
  Clock3D_minutes_radial_config    ( clock_minutes_radial_animStep ) ;

  // Config clock's seconds 2 digits & radial meshes.
  Clock3D_seconds_leftDigit_config ( pDisplayType ) ;
  Clock3D_seconds_rightDigit_config( pDisplayType ) ;
  Clock3D_seconds_radial_config    ( ) ;

  // Config clock's seconds 100th 2 digits & radial meshes.
  Clock3D_second100ths_leftDigit_config ( ) ;
  Clock3D_second100ths_rightDigit_config( ) ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  Clock3D_second100ths_radial_config( ) ;
#endif
}


void
Clock3D_setDisplayType( Digit2D_Type pDisplayType )
{
  if (pDisplayType != clock_displayType)
    Clock3D_config( clock_displayType = pDisplayType ) ;
}


void
Clock3D_cycleDisplayType( )
{
  switch (clock_displayType)
  {
    case DIGIT2D_CURVYBONESKIN:
      Clock3D_setDisplayType( DIGIT2D_CURVYSKINBONE ) ;
      break ;

    case DIGIT2D_CURVYSKINBONE:
      Clock3D_setDisplayType( DIGIT2D_CURVYSKIN ) ;
      break ;

    case DIGIT2D_CURVYSKIN:
      Clock3D_setDisplayType( DIGIT2D_CURVYBONE ) ;
      break ;

    case DIGIT2D_CURVYBONE:
      Clock3D_setDisplayType( DIGIT2D_7SEGSKINBONE ) ;
      break ;

    case DIGIT2D_7SEGSKINBONE:
      Clock3D_setDisplayType( DIGIT2D_7SEGBONESKIN ) ;
      break ;

    case DIGIT2D_7SEGBONESKIN:
      Clock3D_setDisplayType( DIGIT2D_7SEGSKIN ) ;
      break ;

    case DIGIT2D_7SEGSKIN:
      Clock3D_setDisplayType( DIGIT2D_7SEGBONE ) ;
      break ;

    case DIGIT2D_7SEGBONE:
      Clock3D_setDisplayType( CLOCK3D_DISPLAY_TYPE_MAJOR ) ;
      break ;

    default:
      Clock3D_setDisplayType( CLOCK3D_DISPLAY_TYPE_DEFAULT ) ;
      break ;
  } ;
}


void
Clock3D_setDays
( const uint8_t pDays )
{
  if (pDays == clock_days)
    return ;

  const bool isUninitialized = (clock_days == -1) ;
  clock_days = pDays ;
  const uint8_t days_leftDigit  = clock_days / 10 ;
  const uint8_t days_rightDigit = clock_days % 10 ;

  if (isUninitialized)
  {
    Digit3D_setValue( clock_days_leftDigitA, days_leftDigit  ) ;
    clock_days_leftDigitA->mesh->state.isDisabled = (clock_days_leftDigitA->value == 0) ;     // Show A side (if not zero).

    Digit3D_setValue( clock_days_leftDigitB, days_leftDigit  ) ;
    clock_days_leftDigitB->mesh->state.isDisabled = true ;                                    // Hide B side.

    Digit3D_setValue( clock_days_rightDigitA, days_rightDigit ) ;
    clock_days_rightDigitA->mesh->state.isDisabled = false ;                                  // Show A side

    Digit3D_setValue( clock_days_rightDigitB, days_rightDigit ) ;
    clock_days_rightDigitB->mesh->state.isDisabled = true  ;                                  // Hide B side
  }
  else
  {
    if (days_leftDigit != clock_days_leftDigitA->value)
    {
      Digit3D_setValue( clock_days_leftDigitB, days_leftDigit ) ;                 // Set B side value with new digit value.
      clock_days_leftDigitB->mesh->state.isDisabled = (clock_days_leftDigitB->value == 0) ;   // Show B side (if not zero).
  
      if (clock_days_leftDigit_animStep == 0)   // This digit is not currently flipping ...
        clock_days_leftDigit_animStep = 1 ;                                                   // Activate flipping of this digit.
    }

    if (days_rightDigit != clock_days_rightDigitA->value)
    {
      Digit3D_setValue( clock_days_rightDigitB, days_rightDigit ) ;   // Set B side value with new digit value.
      clock_days_rightDigitB->mesh->state.isDisabled = false ;                    // Show B side.
    
      if (clock_days_rightDigit_animStep == 0)
        clock_days_rightDigit_animStep = 1 ;      // Activate flipping of this digit.
    }
  }

  Clock3D_days_leftDigit_config ( clock_days_leftDigit_animStep , clock_displayType ) ;
  Clock3D_days_rightDigit_config( clock_days_rightDigit_animStep, clock_displayType ) ;
}


void
Clock3D_setHours
( const uint8_t pHours )
{
  if (pHours == clock_hours)
    return ;

  const bool isUninitialized = (clock_hours == -1) ;
  clock_hours = pHours ;

  if (clock_is_24h_style( ))
    clock_hours_digitsValue = clock_hours_radialValue = clock_hours ;
  else
  {
    clock_hours_digitsValue = clock_hours % 12 ;
    clock_hours_radialValue  = 2 * clock_hours_digitsValue ;

    if (clock_hours_digitsValue == 0)
      clock_hours_digitsValue = 12 ;
  }

  const uint8_t hours_leftDigit  = clock_hours_digitsValue / 10 ;
  const uint8_t hours_rightDigit = clock_hours_digitsValue % 10 ;

  if (isUninitialized)
  {
    Digit3D_setValue( clock_hours_leftDigitA, hours_leftDigit  ) ;
    clock_hours_leftDigitA->mesh->state.isDisabled = (clock_hours_leftDigitA->value == 0) ;   // Show A side (if not zero).

    Digit3D_setValue( clock_hours_leftDigitB, hours_leftDigit  ) ;
    clock_hours_leftDigitB->mesh->state.isDisabled = true ;                                   // Hide B side.

    Digit3D_setValue( clock_hours_rightDigitA, hours_rightDigit ) ;
    clock_hours_rightDigitA->mesh->state.isDisabled = false ;                                 // Show A side

    Digit3D_setValue( clock_hours_rightDigitB, hours_rightDigit ) ;
    clock_hours_rightDigitB->mesh->state.isDisabled = true  ;                                 // Hide B side

    RadialDial3D_setValue( clock_hours_radial, clock_hours_radialValue ) ;
    Clock3D_hours_radial_config( clock_hours_radial_animStep ) ;
    clock_hours_radial->mesh->state.isDisabled = false ;                                      // Show radial
  }
  else
  {
    if (hours_leftDigit != clock_hours_leftDigitA->value)
    {
      Digit3D_setValue( clock_hours_leftDigitB, hours_leftDigit ) ;                 // Set B side value with new digit value.
      clock_hours_leftDigitB->mesh->state.isDisabled = (clock_hours_leftDigitB->value == 0) ;   // Show B side (if not zero).

      if (clock_hours_leftDigit_animStep == 0)
        clock_hours_leftDigit_animStep = 1 ;                                                      // Activate flipping of this digit.
    }

    if (hours_rightDigit != clock_hours_rightDigitA->value)
    {
      Digit3D_setValue( clock_hours_rightDigitB, hours_rightDigit ) ;   // Set B side value with new digit value.
      clock_hours_rightDigitB->mesh->state.isDisabled = false ;                     // Show B side.

      if (clock_hours_rightDigit_animStep == 0)
        clock_hours_rightDigit_animStep = 1 ;                                         // Activate flipping of this digit.
    }

    if (clock_hours == 0)
    {
      clock_hours_radial_animStep = 1 ;                                         // Activate midnight hours radial animation.
      clock_hours_radial_valueOnAnimStop = clock_hours ;
    }
    else
    {
      RadialDial3D_setValue( clock_hours_radial, clock_hours_radialValue ) ;    // Set hours radial with new value.
      Clock3D_hours_radial_config( clock_hours_radial_animStep ) ;
    }
  }

  Clock3D_hours_leftDigit_config ( clock_hours_leftDigit_animStep , clock_displayType ) ;
  Clock3D_hours_rightDigit_config( clock_hours_rightDigit_animStep, clock_displayType ) ;
}


void
Clock3D_setMinutes
( const uint8_t pMinutes )
{
  if (pMinutes == clock_minutes)
      return ;

  const bool isUninitialized = (clock_minutes == -1) ;
  clock_minutes = pMinutes ;
  const uint8_t minutes_leftDigit  = clock_minutes / 10 ;
  const uint8_t minutes_rightDigit = clock_minutes % 10 ;

  if (isUninitialized)
  {
    Clock3D_minutes_leftDigit_config( clock_minutes_leftDigit_animStep, clock_displayType  ) ;
    Digit3D_setValue( clock_minutes_leftDigitA , minutes_leftDigit  ) ;
    clock_minutes_leftDigitA->mesh->state.isDisabled = false ;   // Show A side
    clock_minutes_leftDigitB->mesh->state.isDisabled = true  ;   // Hide B side

    Clock3D_minutes_rightDigit_config( clock_minutes_rightDigit_animStep, clock_displayType ) ;
    Digit3D_setValue( clock_minutes_rightDigitA, minutes_rightDigit ) ;
    clock_minutes_rightDigitA->mesh->state.isDisabled = false ;   // Show A side
    clock_minutes_rightDigitB->mesh->state.isDisabled = true  ;   // Hide B side
  
    Clock3D_minutes_radial_config( clock_minutes_radial_animStep ) ;
    RadialDial3D_setValue( clock_minutes_radial, clock_minutes ) ;
    clock_minutes_radial->mesh->state.isDisabled = false ;       // Show A side

    return ;
  }

  if (minutes_leftDigit != clock_minutes_leftDigitA->value)
  {
    Digit3D_setValue( clock_minutes_leftDigitB, minutes_leftDigit ) ;   // Set B side value with new digit value.
    clock_minutes_leftDigitB->mesh->state.isDisabled = false ;                      // Show B side.

    if (clock_minutes_leftDigit_animStep == 0)
      clock_minutes_leftDigit_animStep = 1 ;                                          // Activate flipping of this digit.
  }

  if (minutes_rightDigit != clock_minutes_rightDigitA->value)
  {
    Digit3D_setValue( clock_minutes_rightDigitB, minutes_rightDigit ) ;   // Set B side value with new digit value.
    clock_minutes_rightDigitB->mesh->state.isDisabled = false ;                       // Show B side.

    if (clock_minutes_rightDigit_animStep == 0)
      clock_minutes_rightDigit_animStep = 1 ;                                           // Activate flipping of this digit.
  }

  if (clock_minutes == 0)
  {
    clock_minutes_radial_valueOnAnimStop = clock_minutes ;
    clock_minutes_radial_animStep        = 1 ;                       // Activate hour change minutes radial animation.
  }
  else
    RadialDial3D_setValue( clock_minutes_radial, clock_minutes ) ;   // Set radial value with new value.
}


void
Clock3D_setSeconds
( const uint8_t pSeconds )
{
  if (pSeconds == clock_seconds)
    return ;

  const bool isUninitialized = (clock_seconds == -1) ;
  clock_seconds = pSeconds ;
  
  if (isUninitialized)
  {
    // Config clock's seconds 2 digits & radial meshes.
    Clock3D_seconds_leftDigit_config( clock_displayType ) ;
    clock_seconds_leftDigit->mesh->state.isDisabled = false ;

    Clock3D_seconds_rightDigit_config( clock_displayType ) ;
    clock_seconds_rightDigit->mesh->state.isDisabled = false ;

    Clock3D_seconds_radial_config( ) ;
    clock_seconds_radial->mesh->state.isDisabled = false ;
  }

  Digit3D_setValue( clock_seconds_leftDigit , clock_seconds / 10 ) ;
  Digit3D_setValue( clock_seconds_rightDigit, clock_seconds % 10 ) ;
  RadialDial3D_setValue       ( clock_seconds_radial    , clock_seconds      ) ;
}


void
Clock3D_setSecond100ths
( const uint8_t pSecond100ths )
{
  if (pSecond100ths == clock_second100ths)
    return ;

  const bool isUninitialized = (clock_second100ths == -1) ;
  clock_second100ths = pSecond100ths ;

  if (isUninitialized)
  {
    Clock3D_second100ths_leftDigit_config ( ) ;
    clock_second100ths_leftDigit->mesh->state.isDisabled = false ;

    Clock3D_second100ths_rightDigit_config( ) ;
    clock_second100ths_rightDigit->mesh->state.isDisabled = false ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
    Clock3D_second100ths_radial_config( ) ;
    clock_second100ths_radial->mesh->state.isDisabled = false ;
#endif
  }

  Digit3D_setValue( clock_second100ths_leftDigit , clock_second100ths / 10 ) ;   // 1/10 th of a second.
  Digit3D_setValue( clock_second100ths_rightDigit, clock_second100ths % 10 ) ;   // 1/100 th of a second.

#ifdef CLOCK3D_SECOND100THS_RADIAL
  RadialDial3D_setValue( clock_second100ths_radial, clock_second100ths ) ;
#endif
}


void
Clock3D_second100ths_update
( )
{
  // Get miliseconds elapsed.
  static uint16_t miliseconds ;
  time_ms( NULL, &miliseconds ) ;
  Clock3D_setSecond100ths( miliseconds / 10 ) ;
}


void
Clock3D_setTime_DDHHMMSS
( const uint8_t  pDays
, const uint8_t  pHours
, const uint8_t  pMinutes
, const uint8_t  pSeconds
)
{
  Clock3D_setDays   ( pDays    ) ;
  Clock3D_setHours  ( pHours   ) ;
  Clock3D_setMinutes( pMinutes ) ;
  Clock3D_setSeconds( pSeconds ) ;
}


void
Clock3D_updateDDHHMMSS
( )
{
  time_t now ;
  time( &now ) ;
  const struct tm *now_tm = localtime( &now ) ;

  Clock3D_setTime_DDHHMMSS( now_tm->tm_mday   // days
                          , now_tm->tm_hour   // hours
                          , now_tm->tm_min    // minutes
                          , now_tm->tm_sec    // seconds
                          ) ;
}


void
Clock3D_draw
( GContext                      *gCtx
//, Clock3D                     *this    // TODO
, const Cam3D                   *cam
, const int                      w
, const int                      h
, const Mesh3D_TransparencyMode  transparency
)
{
  Mesh3D_draw( gCtx, clock_cube, cam, w, h, Clock3D_isAnimated( ) ? MESH3D_TRANSPARENCY_XRAY : transparency ) ;

  Mesh3D_draw( gCtx, clock_days_leftDigitB ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_days_leftDigitA ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_days_rightDigitB->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_days_rightDigitA->mesh, cam, w, h, transparency ) ;

  Mesh3D_draw( gCtx, clock_hours_leftDigitB ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_hours_leftDigitA ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_hours_rightDigitB->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_hours_rightDigitA->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_hours_radial     ->mesh, cam, w, h, transparency ) ;

  Mesh3D_draw( gCtx, clock_minutes_leftDigitB ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_minutes_leftDigitA ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_minutes_rightDigitB->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_minutes_rightDigitA->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_minutes_radial     ->mesh, cam, w, h, transparency ) ;

  Mesh3D_draw( gCtx, clock_seconds_leftDigit ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_seconds_rightDigit->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_seconds_radial    ->mesh, cam, w, h, transparency ) ;

  Mesh3D_draw( gCtx, clock_second100ths_leftDigit ->mesh, cam, w, h, transparency ) ;
  Mesh3D_draw( gCtx, clock_second100ths_rightDigit->mesh, cam, w, h, transparency ) ;

#ifdef CLOCK3D_SECOND100THS_RADIAL
  Mesh3D_draw( gCtx, clock_second100ths_radial->mesh, cam, w, h, transparency ) ;
#endif
}