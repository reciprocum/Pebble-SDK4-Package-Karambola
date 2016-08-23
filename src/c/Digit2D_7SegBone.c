/*
   Package: Digit2D
   File   : Digit2D_7SegBone.c
   Author : Afonso Santos, Portugal

   Last revision: 22h45 August 18 2016
*/

#include "I2_8.h"
#include "Edge.h"


const I2_8_PathInfo DIGIT2D_7SEGBONE_VERTEXINFO
= { .pointsNum = 6
  , .points    = (I2_8[])
                 { { 120, 120 }     // v0
                 , { 120,   0 }     // v1
                 , { 120,-120 }     // v2
                 , {-120,-120 }     // v3
                 , {-120,   0 }     // v4
                 , {-120, 120 }     // v5
                 }
  }
;

const EdgeInfo DIGIT2D_7SEGBONE_EDGEINFO
= { .edgesNum = 7
  , .edges    = (Edge[])
                { { 0, 1 }      // e0: v0 v1
                , { 1, 2 }      // e1: v1 v2
                , { 2, 3 }      // e2: v2 v3
                , { 3, 4 }      // e3: v3 v4
                , { 4, 5 }      // e4: v4 v5
                , { 5, 0 }      // e5: v5 v0
                , { 1, 4 }      // e6: v1 v4
                }
  }
;

// IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
const unsigned char *DIGIT2D_7SEGBONE_VALUEEDGEMAP_L2R[10]
// Bit index ruller      [00..07]
//                       00000000
//                       01234567
= { (unsigned char[]){ 0b11111100 }   // edge config for value #0: e0 e1 e2 e3 e4 e5
  , (unsigned char[]){ 0b11000000 }   // edge config for value #1: e0 e1
  , (unsigned char[]){ 0b10110110 }   // edge config for value #2: e0 e2 e3 e5 e6
  , (unsigned char[]){ 0b11100110 }   // edge config for value #3: e0 e1 e2 e5 e6
  , (unsigned char[]){ 0b11001010 }   // edge config for value #4: e0 e1 e4 e6
  , (unsigned char[]){ 0b01101110 }   // edge config for value #5: e1 e2 e4 e5 e6
  , (unsigned char[]){ 0b01111110 }   // edge config for value #6: e1 e2 e3 e4 e5 e6
  , (unsigned char[]){ 0b11000100 }   // edge config for value #7: e0 e1 e5
  , (unsigned char[]){ 0b11111110 }   // edge config for value #8: e0 e1 e2 e3 e4 e5 e6
  , (unsigned char[]){ 0b11101110 }   // edge config for value #9: e0 e1 e2 e4 e5 e6
  }
;