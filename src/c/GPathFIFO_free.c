/*
   Package: GPathFIFO
   File   : GPathFIFO_free.c
   Author : Afonso Santos, Portugal

   Last revision: 10h35 August 25 2016
*/

#include "GPathFIFO.h"


GPathFIFO*
GPathFIFO_free( GPathFIFO *this )
{
  if (this != NULL)
  {
    free( this->path.points ) ;
    this->path.points = NULL ;
    this->maxPoints = this->path.num_points = 0 ;
    free( this ) ; this = NULL ;
  }

  return this ;
}