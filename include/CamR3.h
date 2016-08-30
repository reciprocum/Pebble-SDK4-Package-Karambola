/*
   Package: CamR3 - float based 3D camera.
   File   : CamR3.h
   Author : Afonso Santos, Portugal

   Last revision: 17h20 August 29 2016
*/

#pragma once

#include "R2.h"
#include "R3.h"


typedef enum { CAM_PROJECTION_ISOMETRIC
             , CAM_PROJECTION_PERSPECTIVE
             }
CamProjectionMode ;


typedef struct
{
  R3                 viewPoint ;
  R3                 xAxisVersor ;
  R3                 yAxisVersor ;
  R3                 zAxisVersor ;
  float              zoom ;
  CamProjectionMode  projectionMode ;
} CamR3 ;


CamR3*
CamR3_setup
( CamR3                  *cam
, const R3               *viewPoint
, const R3               *lookingAt
, const R3               *upReference
, const float             zoom
, const CamProjectionMode projectionMode
) ;


CamR3*
CamR3_lookAtOriginUpwards
( CamR3                  *cam
, const R3               *viewPoint
, const float             zoom
, const CamProjectionMode projectionMode
) ;

R2*
CamR3_view
( R2           *v2D      // out: camera's film plane 2D coordinates of 3D world point
, const CamR3  *cam      // in: camera used to view the 3D point
, const R3     *v3D      // in: world point's 3D coordinates
) ;