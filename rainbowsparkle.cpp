#include "rainbowsparkle.h"

RainbowSparkle::RainbowSparkle(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  for (int i = 0; i < COUNT; i++)
  {
    pos[i] = newPos();
    pixel[i] = CHSV(random(256), 255, 0);
  }
}

void RainbowSparkle::animate()
{
  for (int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(30);
  }

  for (int i = 0; i < COUNT; i++)
  {
    pixel[i].h++;
    if (pixel[i].h == 0)
    {
      pos[i] = newPos();
    }
    if (pixel[i].h < 30)
    {
      pixel[i].v = (255 / 30) * pixel[i].h;
    }
    else
    {
      pixel[i].v = 255;
    }
    leds[pos[i]] = pixel[i];
  }
}

unsigned int RainbowSparkle::newPos()
{
  for (int tries = 0; tries < 100; tries++)
  {
    bool collision = false;
    unsigned int p = random(ledCount);
    for (int i = 0; i < COUNT; i++)
    {
      if (p == pos[i])
      {
        collision = true;
        break;
      }
    }
    if (!collision)
    {
      return p;
    }
  }
  return random(ledCount);
}

