/*
   Package: RadialDial3D
   File   : RadialDial3D_new.c
   Author : Afonso Santos, Portugal

   Last revision: 18h45 August 29 2016
*/

#include "RadialDial3D.h"


RadialDial3D*
RadialDial3D_new
( RadialDialType type )
{ 
  RadialDial3D *this = malloc(sizeof(RadialDial3D)) ;
  
  if (this == NULL)
    return NULL ;

  switch (this->type = type)
  {
    case RADIAL_DIAL_TYPE_24:
      if ((this->mesh = MeshR3_new( 48, RADIAL_DIAL_24_EDGEINFO.edgesNum, 0 )) == NULL)
        return RadialDial3D_free( this ) ;

      this->mesh->edgeInfo = &RADIAL_DIAL_24_EDGEINFO ;
      break ;

    case RADIAL_DIAL_TYPE_60:
      if ((this->mesh = MeshR3_new( 120, RADIAL_DIAL_60_EDGEINFO.edgesNum, 0 )) == NULL)
        return RadialDial3D_free( this ) ;

      this->mesh->edgeInfo = &RADIAL_DIAL_60_EDGEINFO ;
      break ;

    case RADIAL_DIAL_TYPE_100:
      if ((this->mesh = MeshR3_new( 200, RADIAL_DIAL_100_EDGEINFO.edgesNum, 0 )) == NULL)
        return RadialDial3D_free( this ) ;

      this->mesh->edgeInfo = &RADIAL_DIAL_100_EDGEINFO ;
      break ;
  }

  RadialDial3D_setNull( this ) ;

  return this ;
}