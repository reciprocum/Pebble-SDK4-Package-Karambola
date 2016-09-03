/*
   Package: R3 - float based 3D algebra.
   File   : R3.c
   Author : Afonso Santos, Portugal

   Last revision: 11h20 September 02 2016
*/

#include "R3.h"


const R3 R3_origin        = { .x = 0.0f, .y = 0.0f, .z = 0.0f } ;
const R3 R3_versorPlusX   = { .x =+1.0f, .y = 0.0f, .z = 0.0f } ;
const R3 R3_versorMinusX  = { .x =-1.0f, .y = 0.0f, .z = 0.0f } ;
const R3 R3_versorPlusY   = { .x = 0.0f, .y =+1.0f, .z = 0.0f } ;
const R3 R3_versorMinusY  = { .x = 0.0f, .y =-1.0f, .z = 0.0f } ;
const R3 R3_versorPlusZ   = { .x = 0.0f, .y = 0.0f, .z =+1.0f } ;
const R3 R3_versorMinusZ  = { .x = 0.0f, .y = 0.0f, .z =-1.0f } ;