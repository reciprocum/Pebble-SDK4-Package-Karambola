/*
   File  : Matrix34.h
   Author: Afonso Santos, Portugal

   Last revision: 10h10 August 30 2016
*/

#pragma once

#include "R3.h"


typedef struct
{
  float _11, _12, _13, _14 ;
  float _21, _22, _23, _24 ;
  float _31, _32, _33, _34 ;
} Matrix34 ;


Matrix34*
Matrix34_set
( Matrix34 *M
, const float m11, const float m12, const float m13, const float m14
, const float m21, const float m22, const float m23, const float m24
, const float m31, const float m32, const float m33, const float m34
) ;


// B := A

Matrix34*
Matrix34_assign
( Matrix34       *B
, const Matrix34 *A
) ;


Matrix34*
Matrix34_translation
( Matrix34 *M
, const R3  t
) ;


// Do not change rotation portion, just translation

Matrix34*
Matrix34_setTranslation
( Matrix34 *M
, const R3  t
) ;


Matrix34*
Matrix34_rotation
( Matrix34     *R
, const float   pitch   // rotationX
, const float   yaw     // rotationY
, const float   roll    // rotationZ
) ;


//  C := A X B

Matrix34*
Matrix34_compound
( Matrix34       *C
, const Matrix34 *A
, const Matrix34 *B
) ;


Matrix34*
Matrix34_transformation
( Matrix34  *T
, const R3   rotation
, const R3   translation
) ;


//  t := v X Rot(T)
//  Apply only rotation part of transformation matrix (usefull with face/planar-mesh normals).

R3*
Matrix34_rotate
( R3             *r
, const R3       *v
, const Matrix34 *T
) ;


//  t := v X T

R3*
Matrix34_transform
( R3             *t
, const R3       *v
, const Matrix34 *T
) ;