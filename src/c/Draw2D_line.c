/*
   Package: Draw2D
   File   : Draw2D_line.c
   Author : Afonso Santos, Portugal

   Last revision: 11h55 August 23 2016
*/

#include "Draw2D.h"


void
Draw2D_line
( GContext  *ctx
, int        x0
, int        y0
, int        x1
, int        y1
, ink_t      inkPattern
)
{
  if (inkPattern == INK0)
    return ;
  
  // Bresenham algorithm
  const int dx = abs(x1 - x0) ;
  const int dy = abs(y1 - y0) ;
  const int sx = (x0 < x1) ? 1 : -1 ;
  const int sy = (y0 < y1) ? 1 : -1 ;
  int err = dx - dy ;
  int pixelCount = 0 ;

  int e2 ;

  while (true)
  {
    ++pixelCount ;

    if (pixelCount == inkPattern)
    {
      pixelCount = 0 ;
      graphics_draw_pixel( ctx, (GPoint){ .x = x0, .y = y0 } ) ;
    }

    if ((x0 == x1) && (y0 == y1))
      break ;

    e2 = err << 1 ;
    
    if (e2 > -dy)
    {
      err -= dy ;
      x0 += sx ;
    }
    
    if (e2 < dx)
    {
      err += dx ;
      y0 += sy ;
    }
  }
}