#ifndef BUBBLES_H
#define BUBBLES_H

#include "animation.h"

class Bubbles : public Animation
{
  public:
    Bubbles(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    int stepCount;
    uint8_t color;
    int pos;
};

#endif
