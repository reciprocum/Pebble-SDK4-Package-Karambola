/*
   Package: RadialDial3D
   File   : RadialDial3D_setValue.c
   Author : Afonso Santos, Portugal

   Last revision: 08h45 August 22 2016
*/

#include "RadialDial3D.h"


void
RadialDial3D_setValue
( RadialDial3D *this
, const uint8_t value
)
{
  if (this == NULL)
    return ;

  if (value == this->value)
    return ;    // No change.

  this->value = value ;

  ViewFlags *edgesState = this->mesh->edgesState ;
  unsigned int nRadials = 0 ;

  switch (this->type)
  {
    case RADIAL_DIAL_TYPE_24:
      nRadials = 24 ;
      break ;

    case RADIAL_DIAL_TYPE_60:
      nRadials = 60 ;
      break ;

    case RADIAL_DIAL_TYPE_100:
      nRadials = 100 ;
      break ;
  }
  
  const unsigned int innerRingOffset = nRadials ;
  const unsigned int outerRingOffset = nRadials << 1 ;   // 2 * nRadials

  for ( unsigned int iRadial = 0  ;  iRadial < nRadials  ;  ++iRadial )
    edgesState[iRadial].isDisabled                       // The radial edges.
    = edgesState[iRadial + innerRingOffset].isDisabled   // The inner ring edges.
    = edgesState[iRadial + outerRingOffset].isDisabled   // The outer ring edges.
    = (iRadial > value)
    ;
}