#include "streetlight.h"

StreetLight::StreetLight(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  up = true;
  brightness = 100;
}

void StreetLight::animate()
{
  for (int iLED = 0; iLED < ledCount; iLED++)
  {
    if (iLED % 3 == 0)  // left
    {
      leds[iLED].setRGB(brightness, 0, 0);
    }
    else if (iLED % 3 == 1)  // front
    {
      leds[iLED].setRGB(255, 255, 255);
    }
    else  // right
    {
      leds[iLED].setRGB(0, brightness, 0);
    }
  }
  if (up)
  {
    brightness++;
    if (brightness >= 120)
    {
      up = false;
    }
  }
  else
  {
    brightness--;
    if (brightness <= 50)
    {
      up = true;
    }
  }

}

