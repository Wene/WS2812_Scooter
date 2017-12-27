#ifndef STREETLIGHT_H
#define STREETLIGHT_H

#include "animation.h"

class StreetLight : public Animation
{
  public:
    StreetLight(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    bool up;
    int brightness;
};


#endif
