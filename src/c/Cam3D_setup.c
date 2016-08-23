/*
   Package: Cam3D
   File   : Cam3D_setup.c
   Author : Afonso Santos, Portugal

   Last revision: 12h20 August 23 2016
*/

#include "Cam3D.h"


Cam3D*
Cam3D_setup
( Cam3D                     *cam
, const R3                  *viewPoint
, const R3                  *lookingAt
, const R3                  *upReference
, const float                zoom
, const Cam3D_ProjectionMode projectionMode
)
{
  R3_assign( &cam->viewPoint, viewPoint ) ;

  R3_versor( R3_sub( &cam->zAxisVersor, lookingAt, &cam->viewPoint ) ) ;	              // zAxisVersor = versor( lookingAt - viewPoint )
  R3_versor( R3_crossProduct( &cam->xAxisVersor, &cam->zAxisVersor, upReference ) ) ;	  // xAxisVersor = versor( zAxisVersor X upReference  )
  R3_crossProduct( &cam->yAxisVersor, &cam->zAxisVersor, &cam->xAxisVersor ) ;          // yAxisVersor = zAxisVersor X xAxisVersor
  cam->zoom           = zoom ;
  cam->projectionMode = projectionMode ;

  return cam ;
}