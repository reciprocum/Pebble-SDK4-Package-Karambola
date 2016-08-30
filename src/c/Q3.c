/*
   Package: Q3 - Q15.16 based 3D algebra.
   File   : Q3.c
   Author : Afonso Santos, Portugal

   Last revision: 15h55 August 30 2016
*/

#include "Q3.h"


const Q3 Q3_origin       = { .x = Q_0, .y = Q_0, .z = Q_0 } ;
const Q3 Q3_versorPlusX  = { .x =+Q_1, .y = Q_0, .z = Q_0 } ;
const Q3 Q3_versorMinusX = { .x =-Q_1, .y = Q_0, .z = Q_0 } ;
const Q3 Q3_versorPlusY  = { .x = Q_0, .y =+Q_1, .z = Q_0 } ;
const Q3 Q3_versorMinusY = { .x = Q_0, .y =-Q_1, .z = Q_0 } ;
const Q3 Q3_versorPlusZ  = { .x = Q_0, .y = Q_0, .z =+Q_1 } ;
const Q3 Q3_versorMinusZ = { .x = Q_0, .y = Q_0, .z =-Q_1 } ;