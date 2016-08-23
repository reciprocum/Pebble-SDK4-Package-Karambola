/*
   Package: Interpolator
   File   : Interpolator_TrigonometricYoYo.c
   Author : Afonso Santos, Portugal

   Last revision: 11h45 August 23 2016
*/

#include "FastMath.h"


void
Interpolator_TrigonometricYoYo( float     *result
                              , const int  nSteps
                              )
{
  const float  stepAngle  = DEG_180 / nSteps ;

  // First & last point.
  result[0] = result[nSteps] = 0.0 ;

  for (int iStep = 1  ;  iStep < nSteps  ;  ++iStep)
    result[iStep] = FastMath_sin( iStep * stepAngle ) ;
}