/*
   Package: RadialDial3D
   File   : RadialDial3D_free.c
   Author : Afonso Santos, Portugal

   Last revision: 18h25 August 29 2016
*/

#include "RadialDial3D.h"


RadialDial3D*
RadialDial3D_free
( RadialDial3D *this )
{
  if (this != NULL)
  {
    free( MeshR3_free( this->mesh ) )  ;  this->mesh = NULL ;
    free( this )                       ;  this = NULL ;
  }

  return this ;
}