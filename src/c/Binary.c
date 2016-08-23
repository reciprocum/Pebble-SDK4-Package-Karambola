/*
   Package: Binary
   File   : Binary.c
   Author : Afonso Santos, Portugal

   Last revision: 17h50 August 18 2016
*/

#include <pebble.h>


// Left to right bit indexing.

bool
Binary_isSetL2R
( const unsigned char *bits
, const unsigned int   bitIndex
)
{
  return (bits[bitIndex >> 3] & (0b10000000 >> (bitIndex & 0b111))) != 0 ;   // Leftmost bit has index 0, rightmost bit has index 7.
}


bool
Binary_setL2R
( unsigned char *bits
, const unsigned int   bitIndex
)
{
  return bits[bitIndex >> 3] |= (0b10000000 >> (bitIndex & 0b111)) ;   // Leftmost bit has index 0, rightmost bit has index 7.
}


// Right to left bit indexing.

bool
Binary_isSetR2L
( const unsigned char *bits
, const unsigned int   bitIndex
)
{
  return (bits[bitIndex >> 3] & (0b00000001 << (bitIndex & 0b111))) != 0 ;   // Leftmost bit has index 7, rightmost bit has index 0.
}

bool
Binary_setR2L
( unsigned char *bits
, const unsigned int   bitIndex
)
{
  return bits[bitIndex >> 3] |= (0b00000001 << (bitIndex & 0b111)) ;   // Leftmost bit has index 7, rightmost bit has index 0.
}