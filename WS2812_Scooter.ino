#include "FastLED.h"

// define the number of LEDs
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];


int minBrightness = 10;
int maxBrightness = 100;
int brightness = minBrightness;

void setup() {
    //setting maximum brightness
    FastLED.setBrightness(brightness);

    FastLED.addLeds<WS2812, 10, GRB>(leds, NUM_LEDS); //GRB for the WS2812 color order

    //reset all the LEDs
    memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
    FastLED.show();
    
    delay(2000);
}

bool up = true;

void loop()
{
  for(int iLED = 0; iLED < NUM_LEDS; iLED++)
  {
    if(iLED % 3 == 0)
    {
      leds[iLED].setRGB(255, 0, 0);
    }
    else if(iLED % 3 == 1)
    {
      leds[iLED].setRGB(255, 255, 255);
    }
    else
    {
      leds[iLED].setRGB(0, 255, 0);
    }
  }
  if(up)
  {
    brightness++;
    if(brightness > maxBrightness)
    {
      brightness = maxBrightness;
      up = false;
    }
  }
  else
  {
    brightness--;
    if(brightness < minBrightness)
    {
      brightness = minBrightness;
      up = true;
    }
  }
  FastLED.setBrightness(brightness);
  FastLED.show();
  delay(20);
}
