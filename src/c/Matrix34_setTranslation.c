/*
   Package: Matrix34
   File   : Matrix34_setTranslation.c
   Author : Afonso Santos, Portugal

   Last revision: 10h10 August 30 2016
*/

#include "Matrix34.h"


// Do not change rotation portion, just translation

Matrix34*
Matrix34_setTranslation
( Matrix34 *M
, const R3  t
)
{
  M->_14 = t.x ;
  M->_24 = t.y ;
  M->_34 = t.z ;

  return M ;
}