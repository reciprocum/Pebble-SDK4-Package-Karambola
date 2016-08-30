/*
   Package: RadialDial3D
   File   : RadialDial3D_config.c
   Author : Afonso Santos, Portugal

   Last revision: 10h45 August 30 2016
*/

#include "Matrix34.h"
#include "RadialDial3D.h"


void
RadialDial3D_config
( RadialDial3D          *this               // MUST already contain/point a/to pre-allocated mesh.
, const RadialDialShape  shape
, const float            innerRadius
, const float            outerRadius
, const R3               rotation
, const R3               translation        // Center of the radial handle
)
{
  if ((this == NULL) || (this->mesh == NULL))
    return ;

  MeshR3 *mesh = this->mesh ;

  Matrix34 transformationMtx ;
  Matrix34_transformation( &transformationMtx, rotation, translation ) ;

  // set & rotate the mesh normal.
  Matrix34_rotate( mesh->normal_worldCoord, &R3_versorMinusZ, &transformationMtx ) ;

  // set & transform the mesh vertices.
  int nRadials = 0 ;

  switch (this->type)
  {
    case RADIAL_DIAL_TYPE_24:
      nRadials = 24 ;
      break ;

    case RADIAL_DIAL_TYPE_60:
      nRadials = 60 ;
      break ;

    case RADIAL_DIAL_TYPE_100:
      nRadials = 100 ;
      break ;
  }

  for (int iRadial = 0  ;  iRadial < nRadials  ;  ++iRadial)
  {
    const int32_t  angle    = TRIG_MAX_ANGLE * iRadial / nRadials ;
    const uint16_t angleDeg = ((uint16_t)(360 * iRadial)) / nRadials ;
    const float    nX       = ((float)sin_lookup( angle )) / TRIG_MAX_RATIO ;
    const float    nY       = ((float)cos_lookup( angle )) / TRIG_MAX_RATIO ;

    R3 vInner, vOutter ;

    switch (shape)
    {
      case RADIAL_DIAL_SHAPE_CIRCLE :
        R3_set( &vInner , innerRadius * nX, innerRadius * nY, 0.0 ) ;
        R3_set( &vOutter, outerRadius * nX, outerRadius * nY, 0.0 ) ;
        break ;

      case RADIAL_DIAL_SHAPE_SQUARE:
        if (angleDeg > 315  ||  angleDeg <= 45)
        {
          R3_set( &vInner , innerRadius * nX / nY, innerRadius, 0.0 ) ;
          R3_set( &vOutter, outerRadius * nX / nY, outerRadius, 0.0 ) ;
        }
        else if (angleDeg > 45  &&  angleDeg <= 135)
        {
          R3_set( &vInner , innerRadius, innerRadius * nY / nX, 0.0 ) ;
          R3_set( &vOutter, outerRadius, outerRadius * nY / nX, 0.0 ) ;
        }
        else if (angleDeg > 135  &&  angleDeg <= 225)
        {
          R3_set( &vInner ,-innerRadius * nX / nY,-innerRadius, 0.0 ) ;
          R3_set( &vOutter,-outerRadius * nX / nY,-outerRadius, 0.0 ) ;
        }
        else if (angleDeg > 225  &&  angleDeg <= 315)
        {
          R3_set( &vInner ,-innerRadius,-innerRadius * nY / nX, 0.0 ) ;
          R3_set( &vOutter,-outerRadius,-outerRadius * nY / nX, 0.0 ) ;
        }
     
        break ;
    }

    Matrix34_transform( &mesh->vertices[iRadial].worldCoord           , &vInner , &transformationMtx ) ;
    Matrix34_transform( &mesh->vertices[iRadial + nRadials].worldCoord, &vOutter, &transformationMtx ) ;
  }
}