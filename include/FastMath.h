/*
   package: FastMath
   File   : FastMath.h
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 11h15 August 23 2016
*/

#pragma once

#define PI_2       6.28318531
#define PI_1       3.14159265
#define PI_HALF    1.57079632
#define PI_QUARTER 0.78539816

#define DEG_045  PI_QUARTER
#define DEG_090  PI_HALF
#define DEG_135  (DEG_090+DEG_045)
#define DEG_180  PI_1
#define DEG_225  (DEG_180+DEG_045)
#define DEG_270  (DEG_180+DEG_090)
#define DEG_315  (DEG_270+DEG_045)
#define DEG_360  PI_2


float  FastMath_normalizeAngle( float a ) ;
float  FastMath_reduceAngle   ( float a ) ;
float  FastMath_sin           ( float x ) ;
float  FastMath_cos           ( const float x ) ;
float  FastMath_sqrt          ( const float x ) ;
float  FastMath_abs           ( const float f ) ;