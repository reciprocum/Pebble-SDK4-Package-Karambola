/*
   Package: Sampler
   File   : Sampler_new.c
   Author : Afonso Santos, Portugal

   Last revision: 11h50 August 23 2016
*/

#include "Sampler.h"

#include "Config.h"


Sampler*
Sampler_new
( const uint16_t capacity )
{
  Sampler *this = malloc(sizeof(Sampler)) ;

  if (this == NULL)
  {
    LOGE( "Sampler_new:: this = malloc( ) returned NULL" ) ;
    return NULL ;
  }

  this->samples = malloc((this->capacity = capacity) * sizeof(int16_t)) ;

  if (this->samples == NULL)
  {
    LOGE( "Sampler_new:: this->samples = malloc( ) returned NULL" ) ;
    return Sampler_free( this ) ;
  }

  Sampler_init( this ) ;
  return this ;
}