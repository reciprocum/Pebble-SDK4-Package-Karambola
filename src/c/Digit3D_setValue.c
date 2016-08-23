/*
   Package: Digit3D
   File   : Digit3D.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 23 2016
*/

#include "Digit3D_private.h"


void
Digit3D_setValue
( Digit3D        *this
, const uint8_t   value
)
{
  if (this == NULL)
    return ;              // NOP on NULLs.

  if (value > 9)
    return ;              // Invalid argument.

  if (value == this->value)
    return ;      // No change.

  this->value = value ;

  Digit3D_refreshFromValue( this ) ;
}