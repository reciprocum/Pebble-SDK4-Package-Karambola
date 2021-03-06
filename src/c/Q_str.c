/*
   Package: Q - Fixed point (Q15.16) math. (adapted from libfixmath)
   File   : Q_str.c
   Author : Afonso Santos, Portugal

   Last revision: 18h55 September 01 2016
*/

#include "Q.h"


char*
Q_str
( const Q q )
{
  static char qStr[14] ;

  Q qAbs ;
  char *signal ;

  if (q < Q_0)
  {
    qAbs   = -q ;
    signal = "-" ;
  }
  else
  {
    qAbs   = q ;
    signal = "+" ;
  }

  snprintf( qStr, sizeof(qStr), "%s%d.%05d", signal, Q_to_int(qAbs), (int)(100000 * Q_frac(qAbs)) ) ;

  return qStr ;
}