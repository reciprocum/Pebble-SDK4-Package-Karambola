/*
   Package: Q - Fixed point (Q15.16) math. (adapted from libfixmath)
   File   : Q.c
   Author : Afonso Santos, Portugal

   Last revision: 12h45 September 01 2016
*/

#include "Q.h"


const Q Q_MAX         = 0x7FFFFFFF ;   /* the maximum value of Q */
const Q Q_MIN         = 0x80000000 ;   /* the minimum value of Q */
const Q Q_EPSILON     = 0x00000001 ;   /* the smallest value of Q */

const Q Q_PI          = 0x0003243F ;   /* Q value of PI      */
const Q Q_2_PI        = 0x0006487E ;   /* Q value of 2*PI    */
const Q Q_PI_DIV_2    = 0x0001921F ;   /* Q value of PI/2    */
const Q Q_PI_DIV_4    = 0x0000C90F ;   /* Q value of PI/4    */
const Q Q_3_PI_DIV_4  = 0x00025B2F ;   /* Q value of 3/4*PI  */
const Q Q_4_DIV_PI    = 0x000145F3 ;   /* Q value of 4/PI    */

const Q Q_SQRT2       = 0x00016A09 ;   /* Q value of sqrt(2)  */
const Q Q_E           = 0x0002B7E1 ;   /* Q value of E        */