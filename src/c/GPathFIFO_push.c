/*
   Package: GPathFIFO
   File   : GPathFIFO_push.c
   Author : Afonso Santos, Portugal

   Last revision: 10h35 August 25 2016
*/

#include "GPathFIFO.h"


void
GPathFIFO_push( GPathFIFO *this, const GPoint point )
{
  if (this == NULL)
    return ;
 
  // Extend GPath until capacity is reached.
  if (this->path.num_points < this->maxPoints )
    this->path.num_points++ ;

  // Shift all points down one position.
  for (int pointIdx = this->path.num_points - 1  ;  pointIdx > 0  ;  --pointIdx)
    this->path.points[pointIdx] = this->path.points[pointIdx-1] ;

  this->path.points[0] = point ;
}