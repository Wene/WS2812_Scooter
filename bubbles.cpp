#include "bubbles.h"

Bubbles::Bubbles(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  stepCount = 0;
}

void Bubbles::animate()
{
  int bubbleSize = ledCount / 2;

  // turn everything to black
  for (int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(255);
  }

  // Shuffle new color and position if at start
  if(stepCount == 0)
  {
    pos = random(ledCount);
    color = random(256);
  }

  // color the pixles
  for (int i = 0; i < stepCount + 1; i++)
  {
    int topLed = pos + i;
    int botLed = pos - i;
    if (topLed < ledCount - 1)
    {
      leds[topLed] = CHSV(color, 255, 255 - stepCount * (255 / bubbleSize));
    }
    if (botLed > -1)
    {
      leds[botLed] = CHSV(color, 255, 255 - stepCount * (255 / bubbleSize));
    }
  }

  //
  stepCount++;
  if(stepCount > bubbleSize)
  {
    stepCount = 0;
  }
}

