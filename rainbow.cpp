#include "rainbow.h"

Rainbow::Rainbow(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  rainbowPos = 0;
}

void Rainbow::animate()
{
  uint8_t hue = rainbowPos++;  // get start position and increase global position for next run
  for (int iLED = 0; iLED < ledCount; iLED++)
  {
    leds[iLED] = CHSV(hue, 255, 180);
    hue += 255 / ledCount;  // because it's a uint8_t after 254 it will overflow to 0
  }

}

