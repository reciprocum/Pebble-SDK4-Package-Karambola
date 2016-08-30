/*
   Package: MeshQ3
   File   : MeshQ3_free.c
   Author : Afonso Santos, Portugal

   Last revision: 13h45 August 30 2016
*/

#include "MeshQ3.h"


MeshQ3*
MeshQ3_free
( MeshQ3 *this )
{
  if (this != NULL)
  {
    free( this->normal_worldCoord ) ; this->normal_worldCoord = NULL ;

    free( this->faces )    ; this->faces    = NULL    ; this->facesNum    = 0    ;
    this->edgeInfo = NULL  ; free( this->edgesState ) ; this->edgesState  = NULL ;
    free( this->vertices ) ; this->vertices = NULL    ; this->verticesNum = 0    ;
  }

  return this ;
}
