/*
   Package: Draw2D
   File   : Draw2D.h
   Author : Afonso Santos, Portugal

   Last revision: 11h55 August 23 2016
*/

#pragma once

#include <pebble.h>


#define  ink_t  int

#define  INK0    0
#define  INK100  1
#define  INK50   2
#define  INK33   3
#define  INK25   4
#define  INK20   5


typedef struct
{
  uint8_t isDisabled:1 ;
  uint8_t isHidden  :1 ;
} ViewFlags ;


void
Draw2D_line
( GContext  *ctx
, int        x0
, int        y0
, int        x1
, int        y1
, ink_t      inkPattern
) ;