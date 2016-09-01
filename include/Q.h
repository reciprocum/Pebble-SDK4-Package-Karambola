/*
   Package: Q - Fixed point (Q15.16) math. (adapted from libfixmath)
   File   : Q.h
   Author : Afonso Santos, Portugal

   Last revision: 16h55 September 01 2016
*/

#pragma once

#include <pebble.h>


typedef int32_t Q ;

extern const Q  Q_MAX         ;   /* the maximum value of Q */
extern const Q  Q_MIN         ;   /* the minimum value of Q */
extern const Q  Q_EPSILON     ;   /* the smallest value of Q */

/* Trigonometric constants */
extern const Q  Q_PI          ;   /* Q value of PI      */
extern const Q  Q_2_PI        ;   /* Q value of 2*PI    */
extern const Q  Q_PI_DIV_2    ;   /* Q value of PI/2    */
extern const Q  Q_PI_DIV_4    ;   /* Q value of PI/4    */
extern const Q  Q_3_PI_DIV_4  ;   /* Q value of 3/4*PI  */
extern const Q  Q_4_DIV_PI    ;   /* Q value of 4/PI    */

extern const Q  Q_SQRT2       ;   /* Q value of sqrt(2)  */
extern const Q  Q_E           ;   /* Q value of E        */

#define Q_0  0x00000000           /* Q value of 0.0     */
#define Q_1  0x00010000           /* Q value of 1.0     */

#define Q_float(q) ((q) / (float)Q_1)
#define Q_make(f)  ((Q)((f) * Q_1))
#define Q_mul(a,b) ((Q)(((int64_t)a * b) >> 16))
#define Q_div(a,b) ((Q)(((int64_t)a << 16) / b))
#define Q_int(q)   ((int)((q) >> 16))
#define Q_frac(q)  (Q_float((q) & 0xFFFF))


inline
Q
Q_normalizeAngleRad
( const Q inAngleRad )
{
  return inAngleRad % Q_2_PI ;   // Ditch "surplus" 2*PI turns.
}


inline
Q
Q_reduceAngleRad
( const Q inAngleRad )
{
  Q angleRad = Q_normalizeAngleRad( inAngleRad ) ;

  if (angleRad > Q_PI_DIV_2)
    angleRad -= Q_PI ;
  else if (angleRad < -Q_PI_DIV_2)
    angleRad += Q_PI ;

  return angleRad ;
}


char* Q_str( const Q x ) ;

Q     Q_sqrt( const Q x ) ;

/* Trigonometric functions */
Q     Q_sinRad ( const Q angleRad ) ;
Q     Q_sinRad_( const Q angleRad ) ;   // CAUTION !!! Works only for <angleRad> in [-PI/2, +PI/2] (no angle reduction)
Q     Q_cosRad ( const Q angleRad ) ;
Q     Q_cosRad_( const Q angleRad ) ;   // CAUTION !!! Works only for <angleRad> in [-PI, 0] (no angle reduction)
