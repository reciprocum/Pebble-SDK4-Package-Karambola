/*
   Package: Cam3D
   File   : Cam3D_lookAtOriginUpwards.c
   Author : Afonso Santos, Portugal

   Last revision: 12h20 August 23 2016
*/

#include "Cam3D.h"


Cam3D*
Cam3D_lookAtOriginUpwards
( Cam3D                     *cam
, const R3                  *viewPoint
, const float                zoom
, const Cam3D_ProjectionMode projectionMode
)
{
  // setup 3D camera
  return Cam3D_setup( cam
                    , (viewPoint->x != 0.0  ||  viewPoint->y != 0.0)            // Viewpoint not on Z axis ?
                      ? viewPoint                                               // Use original view point.
                      : &(R3){ .x = 0.00001, .y = 0.00001, .z = viewPoint->z}   // Use epsilon displaced alternate view point (to avoid math indetermination).
                    , &R3_origin                                                // Looking at.
                    , &R3_versorPlusZ                                           // Use R3_versorPlusZ as vertical reference.
                    , zoom                                                      // Zoom level.
                    , projectionMode                                            // Projection mode.
                    ) ;
}