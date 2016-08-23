/*
   Package: Digit2D
   File   : Digit2D_CurvyBone.c
   Author : Afonso Santos, Portugal

   Last revision: 16h00 August 21 2016
*/

#include "I2_8.h"
#include "Edge.h"


const I2_8_PathInfo DIGIT2D_CURVYBONE_VERTEXINFO
= { .pointsNum = 25
  , .points    = (I2_8[])
                 { {-120,+120 }   // v0
                 , { -60,+120 }   // v1
                 , {   0,+120 }   // v2
                 , { +60,+120 }   // v3
                 , {+120,+120 }   // v4
                 , {-120, +90 }   // v5
                 , {+120, +90 }   // v6
                 , {-120, +30 }   // v7
                 , {+120, +30 }   // v8
                 , { -60,   0 }   // v9
                 , { +60,   0 }   // v10
                 , {-120, -30 }   // v11
                 , {+120, -30 }   // v12
                 , {-120, -90 }   // v13
                 , {+120, -90 }   // v14
                 , {-120,-120 }   // v15
                 , { -60,-120 }   // v16
                 , {   0,-120 }   // v17
                 , { +60,-120 }   // v18
                 , {+120,-120 }   // v19
                 , { -60, +30 }   // v20
                 , { +60, +30 }   // v21
                 , {-120,   0 }   // v22
                 , {+120,   0 }   // v23
                 , { -60, -30 }   // v24
                 }
  }
;

const EdgeInfo DIGIT2D_CURVYBONE_EDGEINFO
= { .edgesNum = 37
  , .edges    = (Edge[])
                { {  1,  3 }      // e0
                , {  3,  6 }      // e1
                , {  6,  8 }      // e2
                , {  8, 10 }      // e3
                , {  6, 14 }      // e4
                , { 14, 18 }      // e5
                , { 18, 16 }      // e6
                , { 16, 13 }      // e7
                , { 13,  5 }      // e8
                , {  5,  1 }      // e9
                , {  7,  2 }      // e10
                , {  2, 17 }      // e11
                , { 10,  9 }      // e12
                , {  9, 11 }      // e13
                , { 13, 15 }      // e14
                , { 15, 19 }      // e15
                , { 10, 12 }      // e16
                , { 12, 14 }      // e17
                , { 12, 11 }      // e18
                , {  3, 11 }      // e19
                , {  3, 18 }      // e20
                , {  0,  4 }      // e21
                , {  0, 22 }      // e22
                , {  4, 17 }      // e23
                , {  9,  7 }      // e24
                , {  7,  5 }      // e25
                , { 11, 13 }      // e26
                , {  0,  5 }      // e27
                , {  4,  6 }      // e28
                , { 14, 19 }      // e29
                , { 17, 19 }      // e30
                , { 20, 22 }      // e31
                , { 20, 21 }      // e32
                , { 21, 23 }      // e33
                , { 23, 14 }      // e34
                , { 10, 24 }      // e35
                , { 24, 13 }      // e36
                }
  }
;


const unsigned char *DIGIT2D_CURVYBONE_VALUEEDGEMAP_L2R[10]                           // IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
// Bit index ruller      [00..07]    [08..15]    [16..23]    [24..31]    [32..39]
//                       00000000    00111111    11112222    22222233    33333333
//                       01234567    89012345    67890123    45678901    23456789
= { (unsigned char[]){ 0b11001111, 0b11000000, 0b00000000, 0b00000000, 0b00000000 }   // edge config for value #0: e0 e1 e4 e5 e6 e7 e8 e9
  , (unsigned char[]){ 0b00000010, 0b00110000, 0b00000000, 0b00000000, 0b00000000 }   // edge config for value #1: e6 e10 e11                       
  , (unsigned char[]){ 0b11110000, 0b01000011, 0b00000000, 0b00000100, 0b00011000 }   // edge config for value #2: e0 e1 e2 e3 e9 e12 e13 e14 e15 e29
  , (unsigned char[]){ 0b11110111, 0b01001000, 0b11000000, 0b00000000, 0b00000000 }   // edge config for value #3: e0 e1 e2 e3 e5 e6 e7 e9 e12 e16 e17
  , (unsigned char[]){ 0b00000000, 0b00000000, 0b00111000, 0b00000010, 0b00000000 }   // edge config for value #4: e18 e19 e20 e30
  , (unsigned char[]){ 0b00000111, 0b00000000, 0b00000110, 0b00001001, 0b11100000 }   // edge config for value #5: e5 e6 e7 e21 e22 e28 e31 e32 e33 e34
  , (unsigned char[]){ 0b11000111, 0b11001100, 0b11000000, 0b00000000, 0b00000000 }   // edge config for value #6: e0 e1 e5 e6 e7 e8 e9 e12 e13 e16 e17
  , (unsigned char[]){ 0b00000000, 0b00000000, 0b00000101, 0b00010000, 0b00000000 }   // edge config for value #7: e21 e23 e27
  , (unsigned char[]){ 0b11110111, 0b01001100, 0b11000000, 0b11100000, 0b00000000 }   // edge config for value #8: e0 e1 e2 e3 e5 e6 e7 e9 e12 e13 e16 e17 e24 e25 e26
  , (unsigned char[]){ 0b11011110, 0b01001000, 0b00000000, 0b11000000, 0b00000000 }   // edge config for value #9: e0 e1 e3 e4 e5 e6 e7 e9 e12 e24 e25
  }
;