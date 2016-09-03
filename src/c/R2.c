/*
   Package: R2 - float based 2D algebra.
   File   : R2.c
   Author : Afonso Santos, Portugal

   Last revision: 11h20 September 02 2016
*/

#include "R2.h"


const R2 R2_origin        = { .x = 0.0f, .y = 0.0f } ;
const R2 R2_versorPlusX   = { .x =+1.0f, .y = 0.0f } ;
const R2 R2_versorMinusX  = { .x =-1.0f, .y = 0.0f } ;
const R2 R2_versorPlusY   = { .x = 0.0f, .y =+1.0f } ;
const R2 R2_versorMinusY  = { .x = 0.0f, .y =-1.0f } ;