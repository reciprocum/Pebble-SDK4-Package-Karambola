/*
   Package: Matrix34
   File   : Matrix34_rotate.c
   Author : Afonso Santos, Portugal

   Last revision: 12h30 September 14 2016
*/

#include "Matrix34.h"


//  t := v X Rot(T)
//  Apply only rotation part of transformation matrix (usefull with face/planar-mesh normals).

R3*
Matrix34_rotate
( R3             *r
, const R3       *v
, const Matrix34 *T
)
{
  if (v == NULL)
    return NULL ;
  
  if (T == NULL)
    *r = *v ;    // NOP on NULL transformation.
  else
  {
    const float x = v->x * T->_11  +  v->y * T->_12  +  v->z * T->_13 ;
    const float y = v->x * T->_21  +  v->y * T->_22  +  v->z * T->_23 ;
    const float z = v->x * T->_31  +  v->y * T->_32  +  v->z * T->_33 ;

    R3_set( r, x, y, z ) ;
  }

  return r ;
}