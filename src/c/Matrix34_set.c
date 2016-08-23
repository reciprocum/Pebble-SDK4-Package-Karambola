/*
   Package: Matrix34
   File   : Matrix34_set.c
   Author : Afonso Santos, Portugal

   Last revision: 13h10 August 21 2016
*/

#include "Matrix34.h"


Matrix34*
Matrix34_set
( Matrix34 *M
, const float m11, const float m12, const float m13, const float m14
, const float m21, const float m22, const float m23, const float m24
, const float m31, const float m32, const float m33, const float m34
)
{
  M->_11 = m11 ; M->_12 = m12 ; M->_13 = m13 ; M->_14 = m14 ;
  M->_21 = m21 ; M->_22 = m22 ; M->_23 = m23 ; M->_24 = m24 ;
  M->_31 = m31 ; M->_32 = m32 ; M->_33 = m33 ; M->_34 = m34 ;

  return M ;
} ;
