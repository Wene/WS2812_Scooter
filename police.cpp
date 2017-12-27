#include "police.h"

Police::Police(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  up = true;
  startPos = 0;
}

void Police::animate()
{
  for (int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(50);
  }
  for (int iLED = startPos; iLED < startPos + 4; iLED++)
  {
    leds[iLED].r = 255;
  }
  for (int iLED = ledCount - 1 - startPos; iLED > ledCount - 1 - startPos - 4; iLED--)
  {
    leds[iLED].b = 255;
  }
  if (up)
  {
    startPos++;
    if (startPos >= ledCount - 4)
    {
      startPos = ledCount - 4;
      up = false;
    }
  }
  else
  {
    startPos--;
    if (startPos <= 0)
    {
      startPos = 0;
      up = true;
    }
  }
}

