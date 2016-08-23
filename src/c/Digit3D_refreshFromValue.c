/*
   Package: Digit3D
   File   : Digit3D_refreshFromValue.c
   Author : Afonso Santos, Portugal

   Last revision: 12h55 August 23 2016
*/

#include "Binary.h"
#include "Digit3D.h"


void
Digit3D_refreshFromValue
( Digit3D  *this )
{
  const unsigned char *valueEdgeMapL2R  ;

  switch (this->type)
  {
    case DIGIT2D_7SEGBONE:
      valueEdgeMapL2R = DIGIT2D_7SEGBONE_VALUEEDGEMAP_L2R[this->value] ;
      break ;

    case DIGIT2D_7SEGSKIN:
      valueEdgeMapL2R = DIGIT2D_7SEGSKIN_VALUEEDGEMAP_L2R[this->value] ;
      break ;

    case DIGIT2D_7SEGBONESKIN:
    case DIGIT2D_7SEGSKINBONE:
      valueEdgeMapL2R = DIGIT2D_7SEGSKINBONE_VALUEEDGEMAP_L2R[this->value] ;
      break ;

    case DIGIT2D_CURVYBONE:
      valueEdgeMapL2R = DIGIT2D_CURVYBONE_VALUEEDGEMAP_L2R[this->value] ;
      break ;

    case DIGIT2D_CURVYSKIN:
      valueEdgeMapL2R = DIGIT2D_CURVYSKIN_VALUEEDGEMAP_L2R[this->value] ;
      break ;

    case DIGIT2D_CURVYBONESKIN:
    case DIGIT2D_CURVYSKINBONE:
      valueEdgeMapL2R = DIGIT2D_CURVYSKINBONE_VALUEEDGEMAP_L2R[this->value] ;
      break ;

    default:
      valueEdgeMapL2R = NULL ;
      break ;
  }

  if (valueEdgeMapL2R != NULL)
  {
    const unsigned int  edgesNum   = this->mesh->edgeInfo->edgesNum ;
    ViewFlags          *edgesState = this->mesh->edgesState ;
  
    for ( unsigned int edgeIdx = 0  ;  edgeIdx < edgesNum  ;  ++edgeIdx )
      edgesState[edgeIdx].isDisabled = ! Binary_isSetL2R( valueEdgeMapL2R, edgeIdx ) ;
  }
}