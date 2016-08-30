/*
   Package: Sampler
   File   : Sampler_plot.c
   Author : Afonso Santos, Portugal

   Last revision: 11h50 August 28 2016
*/

#include "Sampler.h"
#include "Config.h"


void
Sampler_plot
( GContext       *gCtx
, Sampler        *this
, const int       pW                // plot area width (pixels)
, const int       pH                // plot area heigth (pixels)
, const uint16_t  pHeadLag
, const uint16_t  pShowMax          // Maximun number of samples to be plotted at once.
, const uint8_t   pShowMin          // Minimum number of samples to be plotted at once.
, int16_t        *ptrSampleMax
, int16_t        *ptrSampleMin
)
{
  if (this == NULL)
    return ;
  
  // MIN( pHeadLag, this->samplesNum - pShowMin )
  const uint16_t headLag   = pHeadLag < this->samplesNum - pShowMin ? pHeadLag : this->samplesNum - pShowMin ;

  // MIN( pShowMax, this->samplesNum     )
  uint16_t       showNum   = pShowMax < this->samplesNum            ? pShowMax : this->samplesNum            ;

  // Near the samples buffer tail cannot show as much samples as asked.
  if (showNum > (this->samplesNum - headLag) )
    showNum = this->samplesNum - headLag ;

  // Normalized world coordinates are a square with both x & y spanning from -1.0 to +1.0.
  const float    wPlotStep = showNum < 3 ? 2.0 : 2.0 / (showNum - 1) ;

  const float   screen_Kx =+0.5f * (pW - 1) ;
  const float   screen_Ky =-0.5f * (pH - 1) ;
  const float   screen_Cy = (pH - 1) ;

  int16_t       plotter ;                              // Sample coords.
  GPoint        sPlotter, sSample ;                    // Screen coords.

  // First iteration of the samples to determine max/min for auto-scaling purpouses.
  int16_t sampleMax = INT16_MIN ;
  int16_t sampleMin = INT16_MAX ;
  int16_t sampleIdx = this->samples_headIdx - headLag ;

  for (int16_t iSample = 0  ;  iSample < showNum  ;  ++iSample)
  {
    const int16_t sample = this->samples[sampleIdx] ;

    if (sample > sampleMax)
      sampleMax = sample ;

    if (sample < sampleMin)
      sampleMin = sample ;

    if (--sampleIdx < 0)
      sampleIdx = this->samplesNum - 1 ;  // Wrap-around the FIFO stack.
  }

  if (ptrSampleMax != NULL)
    *ptrSampleMax = sampleMax ;

  if (ptrSampleMin != NULL)
    *ptrSampleMin = sampleMin ;

  // calculate auto-scale coeficients.
  float plotter_K, plotter_C ;

  if (sampleMax == sampleMin)  // Rare case but would cause div/0 if not properly handled.
    plotter = plotter_K = plotter_C = 0.0 ;
  else
  {
    plotter = sampleMax * sampleMin < 0 ? 0 : (sampleMax < 0 ? sampleMax : sampleMin) ;
    plotter_K = 2.0 / (sampleMax - sampleMin) ;
    plotter_C = -1.0 ;
  }

  const float wPlotter_y = plotter_K * (plotter - sampleMin)  +  plotter_C ;
  sPlotter.y = screen_Ky * (wPlotter_y + 1.0)  +  screen_Cy ;

  // Second iteration of the samples to plot/draw them.
  sampleIdx = this->samples_headIdx - headLag ;

  for (int16_t iSample = 0  ;  iSample < showNum  ;  ++iSample)
  {
    const float   wPlotter_x = 1.0 - iSample * wPlotStep ;
    const int16_t sample     = this->samples[sampleIdx] ;
    const float   wSample_y  = plotter_K * (sample - sampleMin)  +  plotter_C ;

    // Transform normalized world coordinates into screen coordinates.
    sPlotter.x = sSample.x = screen_Kx * (wPlotter_x + 1.0) ;
                 sSample.y = screen_Ky * (wSample_y + 1.0)  +  screen_Cy ;

    // Draw Plotter -> Sample 2D line.
    graphics_draw_line( gCtx, sPlotter, sSample ) ;

    if (--sampleIdx < 0)
      sampleIdx = this->samplesNum - 1 ;  // Wrap-around the FIFO stack.
  }
}