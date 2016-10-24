/*
   Package: GPathFIFO
   File   : GPathFIFO_free.c
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
*/

#include "GPathFIFO.h"


void
GPathFIFO_free( GPathFIFO *this )
{
  if (this != NULL)
  {
    free( this->path.points ) ;
    free( this ) ;
  }
}