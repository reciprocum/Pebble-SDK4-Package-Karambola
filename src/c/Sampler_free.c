/*
   Package: Sampler
   File   : Sampler_free.c
   Author : Afonso Santos, Portugal

   Last revision: 10h35 August 25 2016
*/

#include "Sampler.h"


Sampler*
Sampler_free
( Sampler *this )
{
  if (this != NULL)
  {
    free( this->samples )  ;  this->samples = NULL ;
    this->capacity = this->samplesNum = 0 ;
    free( this )  ;  this = NULL ;
  }

  return this ;
}