/*
   Package: Binary
   File   : Binary_setL2R.c
   Author : Afonso Santos, Portugal

   Last revision: 14h25 August 25 2016
*/

#include <pebble.h>


bool
Binary_setL2R   // Left to right bit indexing.
( unsigned char       *bits
, const unsigned int   bitIndex
)
{
  // Leftmost bit has index 0, rightmost bit has index 7.
  return bits[bitIndex >> 3] |= (0b10000000 >> (bitIndex & 0b111)) ;
}