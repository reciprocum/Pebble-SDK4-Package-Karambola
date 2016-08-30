/*
   Package: Binary
   File   : Binary_isSetR2L.c
   Author : Afonso Santos, Portugal

   Last revision: 14h25 August 25 2016
*/

#include <pebble.h>


bool
Binary_isSetR2L  // Right to left bit indexing.
( const unsigned char *bits
, const unsigned int   bitIndex
)
{
  // Leftmost bit has index 7, rightmost bit has index 0.
  return (bits[bitIndex >> 3] & (0b00000001 << (bitIndex & 0b111))) != 0 ;
}