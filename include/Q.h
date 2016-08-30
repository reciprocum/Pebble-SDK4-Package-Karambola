/*
   Package: Q - Fixed point (Q15.16) math.
   File   : Q.h
   Author : Afonso Santos, Portugal

   Last revision: 14h05 August 30 2016
*/

#pragma once

#include <pebble.h>


typedef int32_t Q ;

#define Q_MAX     0x7FFFFFFF   /* the maximum value of Q */
#define Q_MIN     0x80000000   /* the minimum value of Q */
#define Q_EPSILON 0x00000001   /* the smallest value of Q */

#define Q_0      0x00000000   /* Q value of 0.0      */
#define Q_1      0x00010000   /* Q value of 1.0      */

#define Q_PI     0x0003243F   /* Q value of 'pi'     */
#define Q_2PI    0x0006487E   /* Q value of 2*pi     */
#define Q_PI2    0x0001921F   /* Q value of pi/2     */
#define Q_PI4    0x0000C90F   /* Q value of pi/4     */

#define Q_SQRT2  0x00016A09   /* Q value of sqrt(2)  */
#define Q_E      0x0002B7E1   /* Q value of 'e'      */

#define Q_float(q) ((q) / (float)Q_1)
#define Q_make(f)  ((Q)((f) * Q_1))
#define Q_mul(a,b) ((Q)(((int64_t)a * b) >> 16))
#define Q_div(a,b) ((Q)(((int64_t)a << 16) / b))
#define Q_sq(a)    Q_mul(a,a)
#define Q_int(q)   ((int)((q) >> 16))
#define Q_frac(q)  (Q_float((q) & 0xFFFF))

Q     Q_normalizeAngle( Q a ) ;
Q     Q_reduceAngle   ( Q a ) ;
Q     Q_sqrt          ( const Q x ) ;
char* Q_str           ( const Q x ) ;