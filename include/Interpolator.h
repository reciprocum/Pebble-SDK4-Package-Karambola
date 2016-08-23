/*
   Package: Interpolator
   File   : Interpolator.h
   Author : Afonso Santos, Portugal

   Last revision: 11h45 August 23 2016
*/

#pragma once

void
Interpolator_AccelerateDecelerate( float     *result
                 							   , const int  nSteps
                 								 ) ;

void
Interpolator_TrigonometricYoYo( float     *result
                              , const int  nSteps
                              ) ;