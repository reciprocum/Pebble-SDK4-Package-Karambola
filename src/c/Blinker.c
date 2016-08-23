/*
   Package: Blinker
   File   : Blinker.c
   Author : Afonso Santos, Portugal

   Last revision: 12h00 August 23 2016
*/

#include <pebble.h>

#include "Blinker.h"


void
Blinker_app_timer_handler
( void *data )
{ Blinker *blinker  = (Blinker *)data ;
  blinker->__state  = (blinker->__state == BLINKER_ON ? BLINKER_OFF : BLINKER_ON) ;                  // Toggle the state.
  blinker->value    = (blinker->__state == BLINKER_ON ? blinker->__valueOn : blinker->__valueOff) ;  // Toggle the value.

  // Reschedule the timer.
  blinker->__appTimer = app_timer_register( (blinker->__state == BLINKER_ON ? blinker->__lengthOn : blinker->__lengthOff)
                                          , Blinker_app_timer_handler
                                          , blinker
                                          ) ;
}


Blinker*
Blinker_start
( Blinker        *this           // the blinker being started
, const uint16_t  lengthOn       // miliseconds
, const uint16_t  lengthOff      // miliseconds
, const int       valueOn
, const int       valueOff
)
{
  if (this->__appTimer != NULL)
    return this ;    // This blinker is allready running.

  this->__lengthOn  = lengthOn ;
  this->__lengthOff = lengthOff ;
  this->__valueOn   = valueOn ;
  this->__valueOff  = valueOff ;
  this->__state     = BLINKER_ON ;
  this->value       = this->__valueOn ;

  this->__appTimer = app_timer_register( this->__lengthOn, Blinker_app_timer_handler, this ) ;

  return this ;
}


void
Blinker_stop
( Blinker *this )
{
  if (this->__appTimer != NULL)
  {
    app_timer_cancel( this->__appTimer ) ;
    this->__appTimer = NULL ;
  }
}