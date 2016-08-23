/*
   Package: Digit3D
   File   : Digit3D_setNull.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 23 2016
*/

#include "Digit3D.h"


void
Digit3D_setNull
( Digit3D  *this )
{
  if ((this == NULL) || (this->mesh->edgeInfo == NULL))
    return ;    // NOP on NULLs.

  this->value = -1 ;

  const unsigned int  edgesNum    = this->mesh->edgeInfo->edgesNum ;
  ViewFlags          *edgesState  = this->mesh->edgesState ;
  
  for ( unsigned int me = 0 ; me < edgesNum ; ++me )
    edgesState[me].isDisabled = true ;
}