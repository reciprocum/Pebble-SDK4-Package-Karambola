/*
   Package: Sampler
   File   : Sampler_free.c
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
*/

#include "Sampler.h"


void
Sampler_free
( Sampler *this )
{
  if (this != NULL)
  {
    free( this->samples ) ;
    free( this ) ;
  }
}