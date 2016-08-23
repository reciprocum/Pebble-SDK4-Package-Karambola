/*
   Package: RadialDial3D
   File   : RadialDial3D_setNull.c
   Author : Afonso Santos, Portugal

   Last revision: 08h45 August 22 2016
*/

#include "RadialDial3D.h"


void
RadialDial3D_setNull
( RadialDial3D  *this )
{
  if ((this == NULL) || (this->mesh->edgeInfo == NULL))
    return ;    // NOP on NULLs.

  this->value = -1 ;

  const unsigned int  edgesNum    = this->mesh->edgeInfo->edgesNum ;
  ViewFlags          *edgesState  = this->mesh->edgesState ;

  for ( unsigned int me = 0 ; me < edgesNum ; ++me )
    edgesState[me].isDisabled = true ;
}