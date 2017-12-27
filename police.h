#ifndef POLICE_H
#define POLICE_H

#include "animation.h"

class Police : public Animation
{
  public:
    Police(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    bool up;
    int startPos;
};


#endif
