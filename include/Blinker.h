/*
   Package: Blinker
   File   : Blinker.h
   Author : Afonso Santos, Portugal

   Last revision: 12h00 August 23 2016
*/

#pragma once

#include <pebble.h>


#define  BLINKER_ON   1
#define  BLINKER_OFF  2


typedef struct
{ int       value ;              // Public value, the one being "blinked".
  int       __valueOn ;          // value to set when blinker state is BLINK_ON.
  int       __valueOff ;         // value to set when blinker state is BLINK_OFF.
  uint16_t  __lengthOn ;         // miliseconds
  uint16_t  __lengthOff ;        // miliseconds
  uint8_t   __state ;            // valid values: BLINK_ON, BLINK_OFF
  AppTimer *__appTimer ;
} Blinker ;


void  Blinker_app_timer_handler( void *data ) ;

Blinker*
Blinker_start
( Blinker        *this           // the blinker being started
, const uint16_t  lengthOn       // miliseconds
, const uint16_t  lengthOff      // miliseconds
, const int       valueOn
, const int       valueOff
) ;

void  Blinker_stop( Blinker *this ) ;