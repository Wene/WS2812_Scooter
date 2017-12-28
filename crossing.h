#ifndef CROSSING_H
#define CROSSING_H

#include "animation.h"

class Crossing : public Animation
{
  public:
    Crossing(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    int redPos, greenPos, bluePos;
    bool redUp, greenUp, blueUp;
};


#endif
