#ifndef COLORSNOW_H
#define COLORSNOW_H

#include "animation.h"

class ColorSnow : public Animation
{
  public:
    ColorSnow(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    int pos;
    int color1, color2, color3;
};


#endif
