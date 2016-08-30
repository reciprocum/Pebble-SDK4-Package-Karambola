/*
   Package: Digit3D
   File   : Digit3D_config.c
   Author : Afonso Santos, Portugal

   Last revision: 12h15 August 30 2016
*/

#include "Digit3D_private.h"


void
Digit3D_config
( Digit3D      *this          // The Digit3D being configured.
, Digit2D_Type  type          // Display type can be changed on-the-fly.
, const R2      size          // width & heigth.
, const R2      anchor2D      // 2D translation of the 7 segment display.
, const R3      rotation3D    // 3D rotation of the 7 segment display.
, const R3      anchor3D      // 3D anchor of the segment display.
)
{
  if ( this == NULL          // NOP on NULLs.
    || type > this->typeMax  // Instance was allocated with less memory than what the required DisplayType needs.
     )
    return ;

  switch (this->type = type)
  {
    case DIGIT2D_7SEGBONE:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_7SEGBONE_VERTEXINFO
                                , &DIGIT2D_7SEGBONE_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth = 3 ;
      this->mesh->edgeAlternateMask_L2R = NULL ;
      break ;

    case DIGIT2D_7SEGSKIN:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_7SEGSKIN_VERTEXINFO
                                , &DIGIT2D_7SEGSKIN_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth = 2 ;
      this->mesh->edgeAlternateMask_L2R = NULL ;
      break ;

    case DIGIT2D_7SEGBONESKIN:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_7SEGSKINBONE_VERTEXINFO
                                , &DIGIT2D_7SEGSKINBONE_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth          = 1 ;   // Bone
      this->mesh->strokeWidthAlternate = 1 ;   // Skin
      this->mesh->edgeAlternateMask_L2R = DIGIT2D_7SEGBONESKIN_BONEMASK_L2R ;
      break ;

    case DIGIT2D_7SEGSKINBONE:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_7SEGSKINBONE_VERTEXINFO
                                , &DIGIT2D_7SEGSKINBONE_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth          = 1 ;   // Skin
      this->mesh->strokeWidthAlternate = 1 ;   // Bone
      this->mesh->edgeAlternateMask_L2R = DIGIT2D_7SEGSKINBONE_BONEMASK_L2R ;
      break ;

    case DIGIT2D_CURVYBONE:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_CURVYBONE_VERTEXINFO
                                , &DIGIT2D_CURVYBONE_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth = 3 ;
      this->mesh->edgeAlternateMask_L2R = NULL ;
      break ;

    case DIGIT2D_CURVYSKIN:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_CURVYSKIN_VERTEXINFO
                                , &DIGIT2D_CURVYSKIN_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth = 2 ;
      this->mesh->edgeAlternateMask_L2R = NULL ;
      break ;

    case DIGIT2D_CURVYBONESKIN:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_CURVYSKINBONE_VERTEXINFO
                                , &DIGIT2D_CURVYSKINBONE_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth           = 3 ;   // Bone
      this->mesh->edgeAlternateMask_L2R = DIGIT2D_CURVYBONESKIN_BONEMASK_L2R ;
      break ;

    case DIGIT2D_CURVYSKINBONE:
      MeshR3_setFromI2XSTemplate( this->mesh
                                , &DIGIT2D_CURVYSKINBONE_VERTEXINFO
                                , &DIGIT2D_CURVYSKINBONE_EDGEINFO
                                , size
                                , anchor2D
                                ) ;
      MeshR3_transform( this->mesh, rotation3D, anchor3D ) ;
      this->mesh->strokeWidth           = 2 ;   // Skin
      this->mesh->edgeAlternateMask_L2R = DIGIT2D_CURVYSKINBONE_BONEMASK_L2R ;
      break ;

    default:
      this->mesh->edgeAlternateMask_L2R = NULL ;
      break ;
  }

  Digit3D_refreshFromValue( this ) ;    // Refreshes mesh edges visibility based on current value.
}