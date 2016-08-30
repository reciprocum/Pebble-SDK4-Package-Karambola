/*
   Package: Digit3D
   File   : Digit3D_free.c
   Author : Afonso Santos, Portugal

   Last revision: 18h15 August 29 2016
*/

#include "Digit3D.h"


Digit3D*
Digit3D_free
( Digit3D *this )
{
  if (this != NULL)
  {
    free( MeshR3_free( this->mesh ) )  ;  this->mesh = NULL ;
    free( this )                       ;  this = NULL ;
  }

  return this ;
}