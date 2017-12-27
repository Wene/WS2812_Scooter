#ifndef SPARKLING_H
#define SPARKLING_H

#include "animation.h"

class Sparkling : public Animation
{
  public:
    Sparkling(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
};



#endif
