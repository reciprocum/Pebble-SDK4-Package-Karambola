/*
   Package: RadialDial3D
   File   : RadialDial3D_free.c
   Author : Afonso Santos, Portugal

   Last revision: 08h45 August 22 2016
*/

#include "RadialDial3D.h"


RadialDial3D*
RadialDial3D_free
( RadialDial3D *this )
{
  if (this != NULL)
  {
    free( Mesh3D_free( this->mesh ) ) ;
    this->mesh = NULL ;
  }

  return this ;
}