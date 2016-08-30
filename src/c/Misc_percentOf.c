/*
   Package: Misc
   File   : Misc_percentOf.c
   Author : Afonso Santos, Portugal

   Last revision: 12h45 August 27 2016
*/

#include <pebble.h>

uint8_t
Misc_percentOf( const int16_t pct, const int16_t max )
{
  return (max * pct) / 100 ;
}