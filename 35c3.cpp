#include "35c3.h"

Sparkling::Sparkling(CRGB *ledPtr, int numLEDs) : Animation(ledPtr, numLEDs)
{
  huePos = 0;
}

void Sparkling::animate()
{
  // first dim everything
  for(int i = 0; i < ledCount; i++)
  {
    leds[i].fadeToBlackBy(40);
  }

  // define color pattern
  uint8_t pos = startPos++;
  bool up = true;
  if(pos >= 128)
  {
    up = false;
    uint8_t diff = pos - 127;
    pos = 128 - diff;
  }
  
  int iLED = random(ledCount);
  for(int i = 0; i < ledCount; i++)
  {
    // TODO: sweep up and down and break in iLED    
  }
  // TODO: map iLED to pos- color
  uint8_t hue = map(pos, 0, 128, 96, 160);
   

  leds[iLED] = CHSV(hue, 255, 180);


}

