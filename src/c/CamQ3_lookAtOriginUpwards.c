/*
   Package: CamQ3 - Q15.16 based 3D camera.
   File   : CamQ3_lookAtOriginUpwards.c
   Author : Afonso Santos, Portugal

   Last revision: 14h49 September 06 2016  GMT
*/

#include "CamQ3.h"


CamQ3*
CamQ3_lookAtOriginUpwards
( CamQ3                  *cam
, const Q3               *viewPoint
, const Q                 zoom
, const CamProjectionMode projectionMode
)
{
  // setup 3D camera
  return CamQ3_setup( cam
                    , (viewPoint->x != Q_0  ||  viewPoint->y != Q_0)           // Viewpoint not on Z axis ?
                      ? viewPoint                                              // Use original view point.
                      : &(Q3){ .x = Q_1>>4, .y = Q_1>>4, .z = viewPoint->z }   // Use nearby alternate view point (to avoid math indetermination).
                    , &Q3_origin                                               // Looking at.
                    , &Q3_versorPlusZ                                          // Use Q3_versorPlusZ as vertical reference.
                    , zoom                                                     // Zoom level.
                    , projectionMode                                           // Projection mode.
                    ) ;
}