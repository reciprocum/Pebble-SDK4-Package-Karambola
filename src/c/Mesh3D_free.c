/*
   Package: Mesh3D
   File   : Mesh3D_free.c
   Author : Afonso Santos, Portugal

   Last revision: 14h05 August 22 2016
*/

#include "Mesh3D.h"


Mesh3D*
Mesh3D_free
( Mesh3D *mesh )
{
  if (mesh != NULL)
  {
    free( mesh->normal_worldCoord ) ; mesh->normal_worldCoord = NULL ;

    free( mesh->faces )    ; mesh->faces    = NULL    ; mesh->facesNum    = 0    ;
    mesh->edgeInfo = NULL  ; free( mesh->edgesState ) ; mesh->edgesState  = NULL ;
    free( mesh->vertices ) ; mesh->vertices = NULL    ; mesh->verticesNum = 0    ;
  }

  return mesh ;
}