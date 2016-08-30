/*
   Package: Digit3D
   File   : Digit3D_new.c
   Author : Afonso Santos, Portugal

   Last revision: 18h55 August 29 2016
*/

#include "Digit3D.h"


Digit3D*
Digit3D_new
( Digit2D_Type typeMax )
{
  Digit3D *this = malloc(sizeof(Digit3D)) ;
  
  if (this == NULL)
    return NULL ;

  switch (this->type = this->typeMax = typeMax)
  {
    case DIGIT2D_7SEGBONE:
      this->mesh = MeshR3_new( DIGIT2D_7SEGBONE_VERTEXINFO.pointsNum
                             , DIGIT2D_7SEGBONE_EDGEINFO.edgesNum
                             , 0
                             ) ;
      break ;

    case DIGIT2D_7SEGSKIN:
      this->mesh = MeshR3_new( DIGIT2D_7SEGSKIN_VERTEXINFO.pointsNum
                             , DIGIT2D_7SEGSKIN_EDGEINFO.edgesNum
                             , 0
                             ) ;
      break ;
    
    case DIGIT2D_7SEGBONESKIN:
    case DIGIT2D_7SEGSKINBONE:
      this->mesh = MeshR3_new( DIGIT2D_7SEGSKINBONE_VERTEXINFO.pointsNum
                             , DIGIT2D_7SEGSKINBONE_EDGEINFO.edgesNum
                             , 0
                             ) ;
      break ;

    case DIGIT2D_CURVYBONE:
      this->mesh = MeshR3_new( DIGIT2D_CURVYBONE_VERTEXINFO.pointsNum
                             , DIGIT2D_CURVYBONE_EDGEINFO.edgesNum
                             , 0
                             ) ;
      break ;

    case DIGIT2D_CURVYSKIN:
      this->mesh = MeshR3_new( DIGIT2D_CURVYSKIN_VERTEXINFO.pointsNum
                             , DIGIT2D_CURVYSKIN_EDGEINFO.edgesNum
                             , 0
                             ) ;
      break ;

    case DIGIT2D_CURVYBONESKIN:
    case DIGIT2D_CURVYSKINBONE:
      this->mesh = MeshR3_new( DIGIT2D_CURVYSKINBONE_VERTEXINFO.pointsNum
                             , DIGIT2D_CURVYSKINBONE_EDGEINFO.edgesNum
                             , 0
                             ) ;
      break ;
  }

  if (this->mesh == NULL)
    return Digit3D_free( this ) ;

  Digit3D_setNull( this ) ;

  return this ;
}