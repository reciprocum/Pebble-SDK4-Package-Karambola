/*
   Package: Sampler
   File   : Sampler_free.c
   Author : Afonso Santos, Portugal

   Last revision: 11h50 August 23 2016
*/

#include "Sampler.h"


Sampler*
Sampler_free
( Sampler *this )
{ 
  if (this != NULL)
  {
    free( this->samples ) ;
    this->samples = NULL ;
    this->capacity = this->samplesNum = 0 ;
  }

  return this ;
}