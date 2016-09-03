/*
   package: FastMath
   File   : FastMath.h
   FAST MATH OPERATIONS ON FLOATS

   Last revision: 14h35 September 02 2016
*/

#pragma once

#define PI_MUL_2   6.28318531
#define PI         3.14159265
#define PI_DIV_2   1.57079632
#define PI_DIV_4   0.78539816

#define DEG_045  PI_DIV_4
#define DEG_090  PI_DIV_2
#define DEG_135  (DEG_090+DEG_045)
#define DEG_180  PI
#define DEG_225  (DEG_180+DEG_045)
#define DEG_270  (DEG_180+DEG_090)
#define DEG_315  (DEG_270+DEG_045)
#define DEG_360  PI_MUL_2


float  FastMath_sqrt( const float x ) ;
float  FastMath_abs( const float f ) ;

float  FastMath_normalizeAngleRad( float angleRad ) ;
float  FastMath_reduceAngleRad   ( float angleRad ) ;

/* Avoid: benchmarked to be 10x slower than pebble's native sin_lookup( ) */
float  FastMath_sinRad( float angleRad ) ;

/* Avoid: benchmarked to be 10x slower than pebble's native cos_lookup( ) */
float  FastMath_cosRad( const float angleRad ) ;