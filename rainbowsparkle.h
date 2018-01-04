#ifndef RAINBOWSPARKLE_H
#define RAINBOWSPARKLE_H

#include "animation.h"

#define COUNT 20

class RainbowSparkle : public Animation
{
  public:
    RainbowSparkle(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    CHSV pixel[COUNT];
    unsigned int pos[COUNT];
    unsigned int newPos();
};

#endif
