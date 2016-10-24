/*
   Package: GPathFIFO
   File   : GPathFIFO.h
   Author : Afonso Santos, Portugal

   Last revision: October 20 2016
*/

#pragma once

#include <pebble.h>


typedef struct
{ uint16_t  maxPoints ;
  GPath     path ;
} GPathFIFO ;


GPathFIFO*  GPathFIFO_new( const uint16_t maxPoints ) ;
void        GPathFIFO_init( GPathFIFO *this ) ;
void        GPathFIFO_push( GPathFIFO *this, const GPoint point ) ;
GPath       GPathFIFO_get( GPathFIFO *this ) ;
void        GPathFIFO_free( GPathFIFO *this ) ;