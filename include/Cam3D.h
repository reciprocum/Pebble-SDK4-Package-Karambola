/*
   Package: Cam3D
   File   : Cam3D.h
   Author : Afonso Santos, Portugal

   Last revision: 12h20 August 23 2016
*/

#pragma once

#include "R2.h"
#include "R3.h"


typedef enum { CAM3D_PROJECTION_ISOMETRIC
             , CAM3D_PROJECTION_PERSPECTIVE
             }
Cam3D_ProjectionMode ;


typedef struct
{
  R3                    viewPoint ;
  R3                    xAxisVersor ;
  R3                    yAxisVersor ;
  R3                    zAxisVersor ;
  float                 zoom ;
  Cam3D_ProjectionMode  projectionMode ;
} Cam3D ;


Cam3D*
Cam3D_setup
( Cam3D                     *cam
, const R3                  *viewPoint
, const R3                  *lookingAt
, const R3                  *upReference
, const float                zoom
, const Cam3D_ProjectionMode projectionMode
) ;


Cam3D*
Cam3D_lookAtOriginUpwards
( Cam3D                     *cam
, const R3                  *viewPoint
, const float                zoom
, const Cam3D_ProjectionMode projectionMode
) ;

R2*
Cam3D_view
( R2           *v2D      // out: camera's film plane 2D coordinates of 3D world point
, const Cam3D  *cam      // in: camera used to view the 3D point
, const R3     *v3D      // in: world point's 3D coordinates
) ;