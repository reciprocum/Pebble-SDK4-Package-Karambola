/*
   Package: GPathFIFO
   File   : GPathFIFO_new.c
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
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
  {
    GPathFIFO_free( this ) ;
    return NULL ;
  }

  GPathFIFO_init( this ) ;

  return this ;
}