/*
   Package: Digit2D
   File   : Digit2D_7SegSkinBone.h
   Author : Afonso Santos, Portugal

   Last revision: 15h50 August 21 2016
*/

#pragma once

#include "I2_8.h"
#include "Edge.h"


extern const I2_8_PathInfo  DIGIT2D_7SEGSKINBONE_VERTEXINFO ;
extern const EdgeInfo       DIGIT2D_7SEGSKINBONE_EDGEINFO ;
extern const unsigned char *DIGIT2D_7SEGSKINBONE_VALUEEDGEMAP_L2R[10] ;   // IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
extern const unsigned char *DIGIT2D_7SEGBONESKIN_BONEMASK_L2R ;            // IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
extern const unsigned char *DIGIT2D_7SEGSKINBONE_BONEMASK_L2R ;            // IMPORTANT: use left to right (L2R) bit indexing methods when decoding.
