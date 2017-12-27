#include "sparkling.h"

Sparkling::Sparkling(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{

}

void Sparkling::animate()
{
  int iLED = random(ledCount);
  for(int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(40);
  }
  leds[iLED].setRGB(180, 0, 180);

}

