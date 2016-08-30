/*
   Package: Mesh
   File   : Mesh.h
   Author : Afonso Santos, Portugal

   Last revision: 20h15 August 29 2016
*/

#pragma once


typedef enum { MESH_TRANSPARENCY_SOLID
             , MESH_TRANSPARENCY_XRAY
             , MESH_TRANSPARENCY_WIREFRAME
             }
MeshTransparency ;


typedef struct
{
  uint16_t  edgesNum ;
  uint16_t *edgeIndexes ;
} FaceInfo ;