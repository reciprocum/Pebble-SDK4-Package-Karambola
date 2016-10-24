/*
   Package: MeshR3
   File   : MeshR3_free.c
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
*/

#include "MeshR3.h"


void
MeshR3_free
( MeshR3 *this )
{
  if (this != NULL)
  {
    free( this->normal_worldCoord ) ;
    free( this->faces ) ;
    free( this->edgesState ) ;
    free( this->vertices ) ;
    free( this ) ;
  }
}