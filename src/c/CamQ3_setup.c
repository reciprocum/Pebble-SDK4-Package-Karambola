/*
   Package: CamQ3 - Q15.16 based 3D camera.
   File   : CamQ3_setup.c
   Author : Afonso Santos, Portugal

   Last revision: 12h25 September 14 2016
*/

#include "CamQ3.h"


CamQ3*
CamQ3_setup
( CamQ3                  *cam
, const Q3               *viewPoint
, const Q3               *lookingAt
, const Q3               *upReference
, const Q                 zoom
, const CamProjectionMode projectionMode
)
{
  cam->viewPoint = *viewPoint ;

  Q3_versor( &cam->zAxisVersor, Q3_sub( &cam->zAxisVersor, lookingAt, &cam->viewPoint ) ) ;	        // zAxisVersor = versor( lookingAt - viewPoint )
  Q3_versor( &cam->xAxisVersor, Q3_cross( &cam->xAxisVersor, &cam->zAxisVersor, upReference ) ) ;   // xAxisVersor = versor( zAxisVersor X upReference  )
  Q3_cross( &cam->yAxisVersor, &cam->zAxisVersor, &cam->xAxisVersor ) ;                             // yAxisVersor = zAxisVersor X xAxisVersor
  cam->zoom           = zoom ;
  cam->projectionMode = projectionMode ;

  return cam ;
}