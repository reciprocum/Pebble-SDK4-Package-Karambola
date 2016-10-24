/*
   Package: Digit3D
   File   : Digit3D_free.c
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
*/

#include "Digit3D.h"


void
Digit3D_free
( Digit3D *this )
{
  if (this != NULL)
  {
    MeshR3_free( this->mesh ) ;
    free( this ) ;
  }
}