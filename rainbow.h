#ifndef RAINBOW_H
#define RAINBOW_H

#include "animation.h"
#include "FastLED.h"

class Rainbow : public Animation
{
  public:
    Rainbow(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    uint8_t rainbowPos;
};


#endif
