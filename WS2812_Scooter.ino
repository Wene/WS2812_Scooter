#include "FastLED.h"

// define the number of LEDs
#define NUM_LEDS 60

CRGBArray<NUM_LEDS> leds;

void setup() {
    //setting maximum brightness
    FastLED.setBrightness(80);

    FastLED.addLeds<WS2812, 10, GRB>(leds, NUM_LEDS); //GRB for the WS2812 color order

    //reset all the LEDs
    leds.nscale8(0);
    FastLED.show();

    randomSeed(analogRead(A2));
    
    // delay(2000);
}

bool up = true;
unsigned int loopCount = 0;
int startPos = 0;
uint8_t rainbowPos = 0;
int brightness = 50;

void loop()
{
  loopCount++;
  if(loopCount < 500)
  {
    for(int iLED = 0; iLED < NUM_LEDS; iLED++)
    {
      if(iLED % 3 == 0)
      {
        leds[iLED].setRGB(brightness, 0, 0);
      }
      else if(iLED % 3 == 1)
      {
        leds[iLED].setRGB(brightness, brightness, brightness);
      }
      else
      {
        leds[iLED].setRGB(0, brightness, 0);
      }
    }
    if(up)
    {
      brightness++;
      if(brightness >= 200)
      {
        up = false;
      }
    }
    else
    {
      brightness--;
      if(brightness <= 80)
      {
        up = true;
      }
    }
  }
  else if(loopCount < 1000)
  {
    leds.fadeToBlackBy(50);
    for(int iLED = startPos; iLED < startPos + 4; iLED++)
    {
      leds[iLED].r = 255;
    }
    for(int iLED = NUM_LEDS - 1 - startPos; iLED > NUM_LEDS - 1 - startPos - 4; iLED--)
    {
      leds[iLED].b = 255;
    }
    if(up)
    {
      startPos++;
      if(startPos >= NUM_LEDS - 4)
      {
        startPos = NUM_LEDS - 4;
        up = false;
      }
    }
    else
    {
      startPos--;
      if(startPos <= 0)
      {
        startPos = 0;
        up = true;
      }
    }
  }
  else if(loopCount < 1500)
  {
    uint8_t hue = rainbowPos++;  // get start position and increase global position for next run
    for(int iLED = 0; iLED < NUM_LEDS; iLED++)
    {
      leds[iLED] = CHSV(hue, 255, 255);
      hue += 255 / NUM_LEDS;  // because it's a uint8_t after 254 it will overflow to 0
    }
  }
  else if(loopCount < 8000)
  {
    int iLED = random(NUM_LEDS);
    leds.fadeToBlackBy(40);
    leds[iLED].setRGB(180, 0, 180);
  }
  else
  {
    loopCount = 0;
  }
  FastLED.show();
  delay(20);
}
