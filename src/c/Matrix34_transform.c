/*
   Package: Matrix34
   File   : Matrix34_transform.c
   Author : Afonso Santos, Portugal

   Last revision: 13h10 August 21 2016
*/

#include "Matrix34.h"


//  t := v X T

R3*
Matrix34_transform
( R3             *t
, const R3       *v
, const Matrix34 *T
)
{
  if (T == NULL)
    return R3_assign( t, v ) ;    // NOP on NULL transformation.

  const float x = v->x * T->_11  +  v->y * T->_12  +  v->z * T->_13  +  T->_14 ;
  const float y = v->x * T->_21  +  v->y * T->_22  +  v->z * T->_23  +  T->_24 ;
  const float z = v->x * T->_31  +  v->y * T->_32  +  v->z * T->_33  +  T->_34 ;

  return R3_set( t, x, y, z ) ;
}