/*
   Package: Interpolator
   File   : Interpolator_SinYoYo.c
   Author : Afonso Santos, Portugal

   Last revision: 22h45 September 02 2016
*/

#include <pebble.h>


void
Interpolator_SinYoYo( float     *result
                    , const int  nSteps
                    )
{
//  const float  stepAngleRad  = PI / nSteps ;

  // First & last point.
  result[0] = result[nSteps] = 0.0f ;

  for (int iStep = 1  ;  iStep < nSteps  ;  ++iStep)
  {
    int32_t angle = (TRIG_MAX_ANGLE>>1) * iStep / nSteps ;
    result[iStep] = ((float)sin_lookup( angle )) / TRIG_MAX_RATIO ;
  }
//    result[iStep] = FastMath_sinRad( iStep * stepAngleRad ) ;
}