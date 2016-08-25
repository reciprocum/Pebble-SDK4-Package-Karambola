/*
   Package: GPathFIFO
   File   : GPathFIFO_new.c
   Author : Afonso Santos, Portugal

   Last revision: 10h35 August 25 2016
*/

#include "GPathFIFO.h"


GPathFIFO*
GPathFIFO_new( const uint16_t maxPoints )
{
  GPathFIFO *this = malloc(sizeof(GPathFIFO)) ;

  if (this == NULL)
    return NULL ;

  this->path.points = malloc((this->maxPoints = maxPoints) * sizeof(GPoint)) ;

  if (this->path.points == NULL)
    return GPathFIFO_free( this ) ;

  GPathFIFO_init( this ) ;

  return this ;
}