/*
   Package: MeshQ3
   File   : MeshQ3_free.c
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
*/

#include "MeshQ3.h"


void
MeshQ3_free
( MeshQ3 *this )
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
