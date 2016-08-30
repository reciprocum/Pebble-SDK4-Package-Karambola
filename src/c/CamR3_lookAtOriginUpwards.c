/*
   Package: CamR3 - float based 3D camera.
   File   : CamR3_lookAtOriginUpwards.c
   Author : Afonso Santos, Portugal

   Last revision: 17h20 August 29 2016
*/

#include "CamR3.h"


CamR3*
CamR3_lookAtOriginUpwards
( CamR3                  *cam
, const R3               *viewPoint
, const float             zoom
, const CamProjectionMode projectionMode
)
{
  // setup 3D camera
  return CamR3_setup( cam
                    , (viewPoint->x != 0.0  ||  viewPoint->y != 0.0)            // Viewpoint not on Z axis ?
                      ? viewPoint                                               // Use original view point.
                      : &(R3){ .x = 0.00001f, .y = 0.00001f, .z = viewPoint->z}   // Use epsilon displaced alternate view point (to avoid math indetermination).
                    , &R3_origin                                                // Looking at.
                    , &R3_versorPlusZ                                           // Use R3_versorPlusZ as vertical reference.
                    , zoom                                                      // Zoom level.
                    , projectionMode                                            // Projection mode.
                    ) ;
}