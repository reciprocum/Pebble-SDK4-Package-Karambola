/*
   Package: Digit2D
   File   : Digit2D.h
   Author : Afonso Santos, Portugal

   Last revision: 15h30 August 21 2016
*/

#pragma once

#include "Digit2D_7SegBone.h"
#include "Digit2D_7SegSkin.h"
#include "Digit2D_7SegSkinBone.h"
#include "Digit2D_CurvyBone.h"
#include "Digit2D_CurvySkin.h"
#include "Digit2D_CurvySkinBone.h"


typedef enum { DIGIT2D_7SEGBONE        // [0-9]
             , DIGIT2D_7SEGSKIN        // [0-9]
             , DIGIT2D_7SEGBONESKIN    // [0-9]
             , DIGIT2D_7SEGSKINBONE    // [0-9]
             , DIGIT2D_CURVYBONE       // [0-9]
             , DIGIT2D_CURVYSKIN       // [0-9]
             , DIGIT2D_CURVYSKINBONE   // [0-9]
             , DIGIT2D_CURVYBONESKIN   // [0-9]
             }
Digit2D_Type ;           // Order is IMPORTANT: do NOT change ! Ordered by ascending memory requirements.
