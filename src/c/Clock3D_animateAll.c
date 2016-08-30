/*
   Package: Clock3D
   File   : Clock3D_animateAll.c
   Author : Afonso Santos, Portugal

   Last revision: 17h10 August 25 2016
*/

#include "Clock3D.h"


void
Clock3D_animateAll
( Clock3D  *this )
{
  Clock3D_animateAllDigits( this ) ;
  Clock3D_animateAllRadials( this ) ;
}