/*
   Package: Q2 - Q15.16 based 2D algebra.
   File   : Q2.c
   Author : Afonso Santos, Portugal

   Last revision: 11h20 September 02 2016
*/

#include "Q2.h"


const Q2 Q2_origin       = { .x = Q_0, .y = Q_0 } ;
const Q2 Q2_versorPlusX  = { .x =+Q_1, .y = Q_0 } ;
const Q2 Q2_versorMinusX = { .x =-Q_1, .y = Q_0 } ;
const Q2 Q2_versorPlusY  = { .x = Q_0, .y =+Q_1 } ;
const Q2 Q2_versorMinusY = { .x = Q_0, .y =-Q_1 } ;