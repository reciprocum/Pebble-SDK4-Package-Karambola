/*
   Package: MeshR3
   File   : MeshR3_new.c
   Author : Afonso Santos, Portugal

   Last revision: 17h45 August 29 2016
*/

#include "Config.h"
#include "MeshR3.h"


MeshR3*
MeshR3_new
( const uint16_t verticesNum
, const uint16_t edgesNum
, const uint16_t facesNum
)
{
  MeshR3 *mesh = malloc(sizeof(MeshR3)) ;
  
  if (mesh == NULL)
  {
    return NULL ;
  }

  if (verticesNum > 0)
  {
    mesh->vertices = malloc((mesh->verticesNum = verticesNum) * sizeof(Vertex)) ;
    
    if (mesh->vertices == NULL)
    {
      LOGE( "MeshR3_new:: mesh->vertices == NULL" ) ;
      return MeshR3_free( mesh ) ;
    }
  }

  if (edgesNum > 0)
  {
    mesh->edgesState = malloc(edgesNum * sizeof(ViewFlags)) ;
    
    if (mesh->edgesState == NULL)
    {
      LOGE( "MeshR3_new:: mesh->edgesState == NULL" ) ;
      return MeshR3_free( mesh ) ;
    }
  }

  // Planar faceless meshes need a normal vector.
  if (facesNum == 0)
  {
    mesh->normal_worldCoord = malloc(sizeof(R3)) ;
    
    if (mesh->normal_worldCoord == NULL)
    {
      LOGE( "MeshR3_new:: mesh->normal_worldCoord == NULL" ) ;
      return MeshR3_free( mesh ) ;
    }
  }

  if (facesNum > 0)
  {
    mesh->faces = malloc((mesh->facesNum = facesNum) * sizeof(Face)) ;
    
    if (mesh->faces == NULL)
    {
      LOGE( "MeshR3_new:: mesh->faces == NULL" ) ;
      return MeshR3_free( mesh ) ;
    }
  }

  mesh->strokeWidth = mesh->strokeWidthAlternate = 1 ;
  mesh->strokeColor = mesh->strokeColorAlternate = GColorWhite ;
  mesh->edgeAlternateMask_L2R  = NULL ;      // BitString mask of wich edges use the edgeStroke[Width|Color]]Alternate properties.

  return mesh ;
}