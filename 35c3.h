#ifndef 35C3_H
#define 35C3_H

#include "animation.h"

class Sparkling : public Animation
{
  public:
    Sparkling(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    uint8_t startPos;
};



#endif
