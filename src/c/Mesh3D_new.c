/*
   Package: Mesh3D
   File   : Mesh3D_new.c
   Author : Afonso Santos, Portugal

   Last revision: 14h05 August 22 2016
*/

#include "Config.h"
#include "Mesh3D.h"


Mesh3D*
Mesh3D_new
( const uint16_t verticesNum
, const uint16_t edgesNum
, const uint16_t facesNum
)
{
  Mesh3D *mesh = malloc(sizeof(Mesh3D)) ;
  
  if (mesh == NULL)
  {
    return NULL ;
  }

  if (verticesNum > 0)
  {
    mesh->vertices = malloc((mesh->verticesNum = verticesNum) * sizeof(Vertex)) ;
    
    if (mesh->vertices == NULL)
    {
#ifdef LOG
  APP_LOG( APP_LOG_LEVEL_ERROR, "Mesh3D_new:: mesh->vertices == NULL" ) ;
#endif
      return Mesh3D_free( mesh ) ;
    }
  }

  if (edgesNum > 0)
  {
    mesh->edgesState = malloc(edgesNum * sizeof(ViewFlags)) ;
    
    if (mesh->edgesState == NULL)
    {
#ifdef LOG
  APP_LOG( APP_LOG_LEVEL_ERROR, "Mesh3D_new:: mesh->edgesState == NULL" ) ;
#endif
      return Mesh3D_free( mesh ) ;
    }
  }

  // Planar faceless meshes need a normal vector.
  if (facesNum == 0)
  {
    mesh->normal_worldCoord = malloc(sizeof(R3)) ;
    
    if (mesh->normal_worldCoord == NULL)
    {
#ifdef LOG
  APP_LOG( APP_LOG_LEVEL_ERROR, "Mesh3D_new:: mesh->normal_worldCoord == NULL" ) ;
#endif
      return Mesh3D_free( mesh ) ;
    }
  }

  if (facesNum > 0)
  {
    mesh->faces = malloc((mesh->facesNum = facesNum) * sizeof(Face)) ;
    
    if (mesh->faces == NULL)
    {
#ifdef LOG
  APP_LOG( APP_LOG_LEVEL_ERROR, "Mesh3D_new:: mesh->faces == NULL" ) ;
#endif
      return Mesh3D_free( mesh ) ;
    }
  }

  mesh->strokeWidth = mesh->strokeWidthAlternate = 1 ;
  mesh->strokeColor = mesh->strokeColorAlternate = GColorWhite ;
  mesh->edgeAlternateMask_L2R  = NULL ;      // BitString mask of wich edges use the edgeStroke[Width|Color]]Alternate properties.

  return mesh ;
}