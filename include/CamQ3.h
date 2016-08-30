/*
   Package: CamQ3 - Q15.16 based 3D camera.
   File   : CamQ3.h
   Author : Afonso Santos, Portugal

   Last revision: 13h20 August 29 2016
*/

#pragma once

#include "Q2.h"
#include "Q3.h"


typedef enum { CAM_PROJECTION_ISOMETRIC
             , CAM_PROJECTION_PERSPECTIVE
             }
CamProjectionMode ;


typedef struct
{
  Q3                 viewPoint ;
  Q3                 xAxisVersor ;
  Q3                 yAxisVersor ;
  Q3                 zAxisVersor ;
  Q                  zoom ;
  CamProjectionMode  projectionMode ;
} CamQ3 ;


CamQ3*
CamQ3_setup
( CamQ3                  *this
, const Q3               *viewPoint
, const Q3               *lookingAt
, const Q3               *upReference
, const Q                 zoom
, const CamProjectionMode projectionMode
) ;


CamQ3*
CamQ3_lookAtOriginUpwards
( CamQ3                  *this
, const Q3               *viewPoint
, const Q                 zoom
, const CamProjectionMode projectionMode
) ;

Q2*
CamQ3_view
( Q2           *v2       // out: camera's film plane 2D coordinates of 3D world point
, const CamQ3  *this     // in: camera used to view the 3D point
, const Q3     *v3       // in: world point's 3D coordinates
) ;