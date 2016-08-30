/*
   Package: Matrix34
   File   : Matrix34_translation.c
   Author : Afonso Santos, Portugal

   Last revision: 10h10 August 30 2016
*/

#include "Matrix34.h"


Matrix34*
Matrix34_translation
( Matrix34 *M
, const R3  t
)
{
  M->_11 = 1.0f ; M->_12 = 0.0f ; M->_13 = 0.0f  ;  M->_14 = t.x ;
  M->_21 = 0.0f ; M->_22 = 1.0f ; M->_23 = 0.0f  ;  M->_24 = t.y ;
  M->_31 = 0.0f ; M->_32 = 0.0f ; M->_33 = 1.0f  ;  M->_34 = t.z ;

  return M ;
}