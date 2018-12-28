#ifndef SPARKLING35C3_H
#define SPARKLING35C3_H

#include "animation.h"

class Sparkling35c3 : public Animation
{
  public:
    Sparkling35c3(CRGB *ledPtr, int numLEDs);
    void animate();

  private:
    uint8_t startPos;
};



#endif
