#include "colorsnow.h"

ColorSnow::ColorSnow(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  pos = ledCount;
}

void ColorSnow::animate()
{
  // dim all pixles down
  for (int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(20);
  }

  // move writing position down
  pos--;

  // write moving pixles
  switch (pos % 3)
  {
    case 0:
      if (pos >= ledCount - 3)
      {
        color1 = random(600);
      }
      if (color1 < 256)
      {
        leds[pos] = CHSV(color1, 255, 255);
      }
      break;
    case 1:
      if (pos >= ledCount - 3)
      {
        color2 = random(600);
      }
      if (color2 < 256)
      {
        leds[pos] = CHSV(color2, 255, 255);
      }
      break;
    case 2:
      if (pos >= ledCount - 3)
      {
        color3 = random(600);
      }
      if (color3 < 256)
      {
        leds[pos] = CHSV(color3, 255, 255);
      }
      break;
  }

  // reset animation position after bottom is reached
  if (pos <= 0)
  {
    pos = ledCount;
  }
}

