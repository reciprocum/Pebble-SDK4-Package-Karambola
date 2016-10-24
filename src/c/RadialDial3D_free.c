/*
   Package: RadialDial3D
   File   : RadialDial3D_free.c
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
*/

#include "RadialDial3D.h"


void
RadialDial3D_free
( RadialDial3D *this )
{
  if (this != NULL)
  {
    MeshR3_free( this->mesh ) ;
    free( this ) ;
  }
}