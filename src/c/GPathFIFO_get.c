/*
   Package: GPathFIFO
   File   : GPathFIFO_get.c
   Author : Afonso Santos, Portugal

   Last revision: 10h35 August 25 2016
*/

#include "GPathFIFO.h"


GPath
GPathFIFO_get( GPathFIFO *this )
{
  return this->path ;
}