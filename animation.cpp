#include "animation.h"
#include "Arduino.h"
#include "FastLED.h"

Animation::Animation(CRGB *ledPtr, int numLEDs)
{
  leds = ledPtr;
  ledCount = numLEDs;
}

