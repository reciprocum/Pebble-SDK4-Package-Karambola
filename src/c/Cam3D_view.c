/*
   Package: Cam3D
   File   : Cam3D_view.c
   Author : Afonso Santos, Portugal

   Last revision: 12h20 August 23 2016
*/

#include "Cam3D.h"


R2*
Cam3D_view
( R2           *v2D      // camera's film plane 2D coordinates of 3D world point
, const Cam3D  *cam      // camera used to view the 3D point
, const R3     *v3D      // world point's 3D coordinates
)
{ // TODO: z cliping.
  R3 vCam ;

  R3_sub( &vCam, v3D, &cam->viewPoint ) ;			      // vCamera = norm( v - Eye )

  float k = 1.0 ;  // Assigned value just to mute the compiler warning.

  switch (cam->projectionMode)
  {
    case CAM3D_PROJECTION_PERSPECTIVE:
      k = cam->zoom / R3_dotProduct( &cam->zAxisVersor, &vCam ) ;
      break ;

    case CAM3D_PROJECTION_ISOMETRIC:
      k = cam->zoom ;
      break ;
  }

  return R2_set( v2D
               , k * R3_dotProduct( &cam->xAxisVersor, &vCam )
               , k * R3_dotProduct( &cam->yAxisVersor, &vCam )
               ) ;
}