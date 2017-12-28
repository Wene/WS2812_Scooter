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
  leds[pos].r = 255;

  pos = greenPos / 4;
  if (pos > ledCount - 1)
  {
    pos = ledCount - 1;
  }
  leds[pos].g = 255;

  pos = bluePos / 5;
  if (pos > ledCount - 1)
  {
    pos = ledCount - 1;
  }
  leds[pos].b = 255;

}

