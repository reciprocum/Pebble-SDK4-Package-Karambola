/*
   Package: MeshQ3
   File   : MeshQ3_new.c
   Author : Afonso Santos, Portugal

   Last revision: 13h45 August 30 2016
*/

#include "Config.h"
#include "MeshQ3.h"


MeshQ3*
MeshQ3_new
( const uint16_t verticesNum
, const uint16_t edgesNum
, const uint16_t facesNum
)
{
  MeshQ3 *mesh = malloc(sizeof(MeshQ3)) ;
  
  if (mesh == NULL)
    return NULL ;

  if (verticesNum > 0)
  {
    mesh->vertices = malloc((mesh->verticesNum = verticesNum) * sizeof(Vertex)) ;
    
    if (mesh->vertices == NULL)
    {
      LOGE( "MeshQ3_new:: mesh->vertices == NULL" ) ;
      MeshQ3_free( mesh ) ;
      return NULL ;
    }
  }

  if (edgesNum > 0)
  {
    mesh->edgesState = malloc(edgesNum * sizeof(ViewFlags)) ;
    
    if (mesh->edgesState == NULL)
    {
      LOGE( "MeshQ3_new:: mesh->edgesState == NULL" ) ;
      MeshQ3_free( mesh ) ;
      return NULL ;
    }
  }

  // Planar faceless meshes need a normal vector.
  if (facesNum == 0)
  {
    mesh->normal_worldCoord = malloc(sizeof(Q3)) ;
    
    if (mesh->normal_worldCoord == NULL)
    {
      LOGE( "MeshQ3_new:: mesh->normal_worldCoord == NULL" ) ;
      MeshQ3_free( mesh ) ;
      return NULL ;
    }
  }

  if (facesNum > 0)
  {
    mesh->faces = malloc((mesh->facesNum = facesNum) * sizeof(Face)) ;
    
    if (mesh->faces == NULL)
    {
      LOGE( "MeshQ3_new:: mesh->faces == NULL" ) ;
      MeshQ3_free( mesh ) ;
      return NULL ;
    }
  }

  mesh->strokeWidth = mesh->strokeWidthAlternate = 1 ;
  mesh->strokeColor = mesh->strokeColorAlternate = GColorWhite ;
  mesh->edgeAlternateMask_L2R  = NULL ;      // BitString mask of wich edges use the edgeStroke[Width|Color]]Alternate properties.

  return mesh ;
}