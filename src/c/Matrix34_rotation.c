/*
   Package: Matrix34
   File   : Matrix34_rotation.c
   Author : Afonso Santos, Portugal

   Last revision: 12h20 August 23 2016
*/

#include "FastMath.h"
#include "Matrix34.h"


Matrix34*
Matrix34_rotation
( Matrix34     *R
, const float   pitch   // rotationX
, const float   yaw     // rotationY
, const float   roll    // rotationZ
)
{
  const float halfPitch = 0.5f * FastMath_normalizeAngle( pitch ) ;
  const float halfYaw   = 0.5f * FastMath_normalizeAngle( yaw ) ;
  const float halfRoll  = 0.5f * FastMath_normalizeAngle( roll ) ;

  const float sinPitch = FastMath_sin( halfPitch ) ;
  const float cosPitch = FastMath_cos( halfPitch ) ;
  const float sinYaw   = FastMath_sin( halfYaw ) ;
  const float cosYaw   = FastMath_cos( halfYaw ) ;
  const float sinRoll  = FastMath_sin( halfRoll ) ;
  const float cosRoll  = FastMath_cos( halfRoll ) ;

  const float x = (cosYaw * sinPitch * cosRoll) + (sinYaw * cosPitch * sinRoll) ;
  const float y = (sinYaw * cosPitch * cosRoll) - (cosYaw * sinPitch * sinRoll) ;
  const float z = (cosYaw * cosPitch * sinRoll) - (sinYaw * sinPitch * cosRoll) ;
  const float w = (cosYaw * cosPitch * cosRoll) + (sinYaw * sinPitch * sinRoll) ;

  const float xx = x * x ;
  const float yy = y * y ;
  const float zz = z * z ;
  const float xy = x * y ;
  const float zw = z * w ;
  const float zx = z * x ;
  const float yw = y * w ;
  const float yz = y * z ;
  const float xw = x * w ;

  R->_11 = 1.0f - (2.0f * (yy + zz)) ;
  R->_12 = 2.0f * (xy - zw) ;
  R->_13 = 2.0f * (zx + yw) ;

  R->_21 = 2.0f * (xy + zw) ;
  R->_22 = 1.0f - (2.0f * (zz + xx)) ;
  R->_23 = 2.0f * (yz - xw) ;

  R->_31 = 2.0f * (zx - yw) ;
  R->_32 = 2.0f * (yz + xw) ;
  R->_33 = 1.0f - (2.0f * (yy + xx)) ;

  R->_14 = 0.0f ;  // No translation.
  R->_24 = 0.0f ;  // No translation.
  R->_34 = 0.0f ;  // No translation.

  return R ;
}