#ifndef ANIMATION_H
#define ANIMATION_H
#include "FastLED.h"

class Animation
{
  protected:
    CRGB *leds;
    int ledCount;

  public:
    Animation(CRGB *ledPtr, int numLEDs);
    void animate();
};


#endif
