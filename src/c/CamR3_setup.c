/*
   Package: CamR3 - float based 3D camera.
   File   : CamR3_setup.c
   Author : Afonso Santos, Portugal

   Last revision: 11h00 September 02 2016
*/

#include "CamR3.h"


CamR3*
CamR3_setup
( CamR3                  *cam
, const R3               *viewPoint
, const R3               *lookingAt
, const R3               *upReference
, const float             zoom
, const CamProjectionMode projectionMode
)
{
  R3_assign( &cam->viewPoint, viewPoint ) ;

  R3_versor( &cam->zAxisVersor, R3_sub( &cam->zAxisVersor, lookingAt, &cam->viewPoint ) ) ;	        // zAxisVersor = versor( lookingAt - viewPoint )
  R3_versor( &cam->xAxisVersor, R3_cross( &cam->xAxisVersor, &cam->zAxisVersor, upReference ) ) ;	  // xAxisVersor = versor( zAxisVersor X upReference  )
  R3_cross( &cam->yAxisVersor, &cam->zAxisVersor, &cam->xAxisVersor ) ;                             // yAxisVersor = zAxisVersor X xAxisVersor
  cam->zoom           = zoom ;
  cam->projectionMode = projectionMode ;

  return cam ;
}