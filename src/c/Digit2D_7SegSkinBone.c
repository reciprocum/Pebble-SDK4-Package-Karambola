/*
   Package: Digit2D
   File   : Digit2D_7SegSkinBone.c
   Author : Afonso Santos, Portugal

   Last revision: 15h55 August 21 2016
*/

#include "I2_8.h"
#include "Edge.h"


const I2_8_PathInfo DIGIT2D_7SEGSKINBONE_VERTEXINFO
= { .pointsNum = 20
  , .points    = (I2_8[])
                 { { 120, 120 }   // v0   (skin)
                 , { 120,   0 }   // v1   (skin)
                 , { 120,-120 }   // v2   (skin)
                 , {-120,-120 }   // v3   (skin)
                 , {-120,   0 }   // v4   (skin)
                 , {-120, 120 }   // v5   (skin)
                 , {  84, 102 }   // v6   (skin)
                 , {  84,   9 }   // v7   (skin)
                 , { -84,   9 }   // v8   (skin)
                 , { -84, 102 }   // v9   (skin)
                 , {  84,  -9 }   // v10  (skin)
                 , {  84,-102 }   // v11  (skin)
                 , { -84,-102 }   // v12  (skin)
                 , { -84,  -9 }   // v13  (skin)

                 , { 102, 111 }   // v14  (bone)
                 , { 102,   0 }   // v15  (bone)
                 , { 102,-111 }   // v16  (bone)
                 , {-102,-111 }   // v17  (bone)
                 , {-102,   0 }   // v18  (bone)
                 , {-102, 111 }   // v19  (bone)
                 }
  }
;

const EdgeInfo DIGIT2D_7SEGSKINBONE_EDGEINFO
= { .edgesNum = 31
  , .edges    = (Edge[])
                { {  0,  1 }      // e0   (skin)
                , {  1,  2 }      // e1   (skin)
                , {  2,  3 }      // e2   (skin)
                , {  3,  4 }      // e3   (skin)
                , {  4,  5 }      // e4   (skin)
                , {  5,  0 }      // e5   (skin)
                , {  6,  7 }      // e6   (skin)
                , {  7,  8 }      // e7   (skin)
                , {  8,  9 }      // e8   (skin)
                , {  9,  6 }      // e9   (skin)
                , { 10, 11 }      // e10  (skin)
                , { 11, 12 }      // e11  (skin)
                , { 12, 13 }      // e12  (skin)
                , { 13, 10 }      // e13  (skin)
                , {  6,  0 }      // e14  (skin)
                , {  7,  1 }      // e15  (skin)
                , {  1, 10 }      // e16  (skin)
                , {  2, 11 }      // e17  (skin)
                , {  3, 12 }      // e18  (skin)
                , {  4, 13 }      // e19  (skin)
                , {  4,  8 }      // e20  (skin)
                , {  5,  9 }      // e21  (skin)
                , {  8, 13 }      // e22  (skin)
                , {  7, 10 }      // e23  (skin)

                , { 14, 15 }      // e24  (bone)
                , { 15, 16 }      // e25  (bone)
                , { 16, 17 }      // e26  (bone)
                , { 17, 18 }      // e27  (bone)
                , { 18, 19 }      // e28  (bone)
                , { 19, 14 }      // e29  (bone)
                , { 15, 18 }      // e30  (bone)
                }
  }
;

const unsigned char *DIGIT2D_7SEGSKINBONE_VALUEEDGEMAP_L2R[10]            // IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
// Bit index ruller      [00..07]    [08..15]    [16..23]    [24..31]
//                       00000000    00111111    11112222    22222233
//                       01234567    89012345    67890123    45678901                                  [...................SKIN.......................]   [...........BONE..........]
= { (unsigned char[]){ 0b11111110, 0b11111000, 0b00000011, 0b11111100 }   // edge config for value #0: e0 e1 e2 e3 e4 e5 e6 e8 e9 e10 e11 e12 e22 e23     e24 e25 e26 e27 e28 e29
  , (unsigned char[]){ 0b11000010, 0b00100010, 0b01000001, 0b11000000 }   // edge config for value #1: e0 e1 e6 e10 e14 e17 e23                           e24 e25
  , (unsigned char[]){ 0b10110111, 0b01011100, 0b11001100, 0b10110110 }   // edge config for value #2: e0 e2 e3 e5 e6 e7 e9 e11 e12 e13 e16 e17 e20 e21   e24 e26 e27 e29 e30
  , (unsigned char[]){ 0b11100111, 0b01110100, 0b00100110, 0b11100110 }   // edge config for value #3: e0 e1 e2 e5 e6 e7 e9 e10 e11 e13 e18 e21 e22       e24 e25 e26 e29 e30
  , (unsigned char[]){ 0b11001011, 0b10100110, 0b01010100, 0b11001010 }   // edge config for value #4: e0 e1 e4 e6 e7 e8 e10 e13 e14 e17 e19 e21          e24 e25 e28 e30
  , (unsigned char[]){ 0b01101101, 0b11110111, 0b00110000, 0b01101110 }   // edge config for value #5: e1 e2 e4 e5 e7 e8 e9 e10 e11 e13 e14 e15 e18 e19   e25 e26 e28 e29 e30
  , (unsigned char[]){ 0b01111101, 0b11111111, 0b00000000, 0b01111110 }   // edge config for value #6: e1 e2 e3 e4 e5 e7 e8 e9 e10 e11 e12 e13 e14 e15    e25 e26 e27 e28 e29 e30
  , (unsigned char[]){ 0b11000110, 0b01100000, 0b01000101, 0b11000100 }   // edge config for value #7: e0 e1 e5 e6 e9 e10 e17 e21 e23                     e24 e25 e29
  , (unsigned char[]){ 0b11111111, 0b11111100, 0b00000000, 0b11111110 }   // edge config for value #8: e0 e1 e2 e3 e4 e5 e6 e7 e8 e9 e10 e11 e12 e13      e24 e25 e26 e27 e28 e29 e30 
  , (unsigned char[]){ 0b11101111, 0b11110100, 0b00110000, 0b11101110 }   // edge config for value #9: e0 e1 e2 e4 e5 e6 e7 e8 e9 e10 e11 e13 e18 e19     e24 e25 e26 e28 e29 e30
  }
;

const unsigned char *DIGIT2D_7SEGBONESKIN_BONEMASK_L2R                // IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
// Bit index ruller    [00..07]    [08..15]    [16..23]    [24..31]
//                     00000000    00111111    11112222    22222233
//                     01234567    89012345    67890123    45678901
= (unsigned char[]){ 0b11111111, 0b11111111, 0b11111111, 0b00000000 }
;

const unsigned char *DIGIT2D_7SEGSKINBONE_BONEMASK_L2R                // IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
// Bit index ruller    [00..07]    [08..15]    [16..23]    [24..31]
//                     00000000    00111111    11112222    22222233
//                     01234567    89012345    67890123    45678901
= (unsigned char[]){ 0b00000000, 0b00000000, 0b00000000, 0b11111111 }
;