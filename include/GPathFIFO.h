/*
   Package: GPathFIFO
   File   : GPathFIFO.h
   Author : Afonso Santos, Portugal

   Last revision: 10h35 August 25 2016
*/

#pragma once

#include <pebble.h>


typedef struct
{ uint16_t  maxPoints ;
  GPath     path ;
} GPathFIFO ;


GPathFIFO*  GPathFIFO_new( const uint16_t maxPoints ) ;
GPathFIFO*  GPathFIFO_free( GPathFIFO *this ) ;
void        GPathFIFO_init( GPathFIFO *this ) ;
void        GPathFIFO_push( GPathFIFO *this, const GPoint point ) ;
GPath       GPathFIFO_get( GPathFIFO *this ) ;
