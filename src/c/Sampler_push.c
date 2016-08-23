/*
   Package: Sampler
   File   : Sampler_push.c
   Author : Afonso Santos, Portugal

   Last revision: 11h50 August 23 2016
*/

#include "Sampler.h"


void
Sampler_push
( Sampler *this
, int16_t  sample
)
{
  if (this == NULL)
    return ;
 
  if (this->samplesNum < this->capacity )
    this->samples_headIdx = this->samplesNum++ ;
  else
  { // Capacity full! ...

    // ... so we must move the headIdx forward...
    this->samples_headIdx++ ;

    if (this->samples_headIdx == this->capacity)
      this->samples_headIdx = 0 ;                       // and wrap-around the FIFO stack if necessary.
  }

  this->samplesAcum += sample - this->samples[this->samples_headIdx] ;  // Refresh acum stats. Discard outgoing sample.
  this->samples[this->samples_headIdx] = sample ;
}