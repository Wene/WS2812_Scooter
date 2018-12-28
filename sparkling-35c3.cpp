#include "sparkling-35c3.h"

Sparkling35c3::Sparkling35c3(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  startPos = 0;
}

void Sparkling35c3::animate()
{
  // first dim everything
  for(int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(40);
  }

  // define color pattern
  uint8_t pos = startPos++;
  bool up = true;
  if(pos >= 128)  // limit here is 128 because it will first be decremented in following loop
  {
    up = false;
    uint8_t diff = pos - 128;
    pos = 128 - diff;
  }

  // find random led to flash and its corresponting position
  int iLED = random(ledCount);
  for(int i = 0; i < ledCount; i++)
  {
    if(up)
    {
      pos++;
    }
    else
    {
      pos--;
    }
    if(pos >= 127)
    {
      up = false;
    }
    else if(pos == 0)
    {
      up = true;
    }
    if(iLED == i)
    {
      break;
    }
  }
  
  // map color to pos
  uint8_t hue = map(pos, 0, 127, 96, 160);

  // set pixel color
  leds[iLED] = CHSV(hue, 255, 180);
}

