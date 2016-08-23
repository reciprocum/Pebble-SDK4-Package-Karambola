/*
   Package: Matrix34
   File   : Matrix34_assign.c
   Author : Afonso Santos, Portugal

   Last revision: 13h10 August 21 2016
*/

#include "Matrix34.h"


// B := A

Matrix34*
Matrix34_assign
( Matrix34       *B
, const Matrix34 *A
)
{
  B->_11 = A->_11 ; B->_12 = A->_12 ; B->_13 = A->_13 ; B->_14 = A->_14 ;
  B->_21 = A->_21 ; B->_22 = A->_22 ; B->_23 = A->_23 ; B->_24 = A->_24 ;
  B->_31 = A->_31 ; B->_32 = A->_32 ; B->_33 = A->_33 ; B->_34 = A->_34 ;

  return B ;
}