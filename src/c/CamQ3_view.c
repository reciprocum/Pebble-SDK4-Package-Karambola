/*
   Package: CamQ3 - Q15.16 based 3D camera.
   File   : CamQ3_view.c
   Author : Afonso Santos, Portugal

   Last revision: 14h07 August 29 2016
*/

#include "CamQ3.h"


Q2*
CamQ3_view
( Q2           *v2       // camera's film plane 2D coordinates of 3D world point
, const CamQ3  *cam      // camera used to view the 3D point
, const Q3     *v3       // world point's 3D coordinates
)
{ // TODO: z cliping.
  Q3 vCam ;

  Q3_sub( &vCam, v3, &cam->viewPoint ) ;			      // vCamera := v - Eye

  Q k = Q_1 ;  // Assigned value just to mute the compiler warning.

  switch (cam->projectionMode)
  {
    case CAM_PROJECTION_PERSPECTIVE:
      {
        const Q z = Q3_dotProduct( &cam->zAxisVersor, &vCam ) ;
        k = Q_div( cam->zoom, z ) ;
      }
      break ;

    case CAM_PROJECTION_ISOMETRIC:
      k = cam->zoom ;
      break ;
  }

  const Q  x = Q3_dotProduct( &cam->xAxisVersor, &vCam ) ;
  const Q  y = Q3_dotProduct( &cam->yAxisVersor, &vCam ) ;

  return Q2_set( v2
               , Q_mul( k, x )
               , Q_mul( k, y )
               ) ;
}