/*
   Package: Digit3D
   File   : Digit3D_free.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 23 2016
*/

#include "Digit3D.h"


Digit3D*
Digit3D_free
( Digit3D *this )
{
  if (this != NULL)
  {
    free( Mesh3D_free( this->mesh ) ) ;
    this->mesh = NULL ;
  }

  return this ;
}