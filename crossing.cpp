#include "crossing.h"

Crossing::Crossing(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  redUp = true;
  redPos = 0;
  greenUp = false;
  greenPos = ledCount * 4;
  blueUp = true;
  bluePos = ledCount * 2;
}

void Crossing::animate()
{
  // fade all out
  for (int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(10);
  }

  // move red
  if (redUp)
  {
    redPos++;
    if (redPos >= ledCount * 3)
    {
      redUp = false;
    }
  }
  else
  {
    redPos--;
    if (redPos <= 0)
    {
      redPos = 0;
      redUp = true;
    }
  }

  // move green
  if (greenUp)
  {
    greenPos++;
    if (greenPos >= ledCount * 4)
    {
      greenUp = false;
    }
  }
  else
  {
    greenPos--;
    if (greenPos <= 0)
    {
      greenPos = 0;
      greenUp = true;
    }
  }

  // move blue
  if (blueUp)
  {
    bluePos++;
    if (bluePos >= ledCount * 5)
    {
      blueUp = false;
    }
  }
  else
  {
    bluePos--;
    if (bluePos <= 0)
    {
      bluePos = 0;
      blueUp = true;
    }
  }

  // display the pixles
  int pos = redPos / 3;
  if (pos > ledCount - 1)
  {
    pos = ledCount - 1;
  }
  if (redUp)
  {
    leds[pos].r = 255 / 3 + ((255 / 3) * (redPos % 3));
  }
  else
  {
    leds[pos].r = 255 - ((255 / 3) * (redPos % 3));
  }

  pos = greenPos / 4;
  if (pos > ledCount - 1)
  {
    pos = ledCount - 1;
  }
  if (greenUp)
  {
    leds[pos].g = 255 / 4 + ((255 / 4) * (greenPos % 4));
  }
  else
  {
    leds[pos].g = 255 - ((255 / 4) * (greenPos % 4));
  }

  pos = bluePos / 5;
  if (pos > ledCount - 1)
  {
    pos = ledCount - 1;
  }
  if (blueUp)
  {
    leds[pos].b = 255 / 5 + ((255 / 5) * (bluePos % 5));
  }
  else
  {
    leds[pos].b = 255 - ((255 / 5) * (bluePos % 5));
  }

}

