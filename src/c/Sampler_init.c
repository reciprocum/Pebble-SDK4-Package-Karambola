/*
   Package: Sampler
   File   : Sampler_init.c
   Author : Afonso Santos, Portugal

   Last revision: 11h50 August 23 2016
*/

#include "Sampler.h"


void
Sampler_init
( Sampler *this )
{
  this->samplesNum = this->samples_headIdx = this->samplesAcum = 0 ;

  for ( uint8_t sampleIdx = 0  ;  sampleIdx < this->capacity  ;  ++sampleIdx )
    this->samples[sampleIdx] = 0 ;
}