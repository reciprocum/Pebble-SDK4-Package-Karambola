/*
   Package: MeshR3
   File   : MeshR3_free.c
   Author : Afonso Santos, Portugal

   Last revision: 17h05 August 29 2016
*/

#include "MeshR3.h"


MeshR3*
MeshR3_free
( MeshR3 *this )
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