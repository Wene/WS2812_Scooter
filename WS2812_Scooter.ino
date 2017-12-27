#include "FastLED.h"
#include "key.h"
#include "rainbow.h"

// define the number of LEDs
#define NUM_LEDS 60

#define LED_PIN 10
#define BTN_PIN 11

Key key(BTN_PIN);

CRGBArray<NUM_LEDS> leds;

Rainbow rainbow(leds, NUM_LEDS);

void setup() {
  //setting maximum brightness
  FastLED.setBrightness(80);

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  //GRB for the WS2812 color order

  //reset all the LEDs
  leds.nscale8(0);
  FastLED.show();

  // initialize random renerator with true random value (hopefully)
  randomSeed(analogRead(A2));

}

bool up = true;
int startPos = 0;
int brightness = 100;

int mode = 1;
uint8_t countDown = 255;

void loop()
{
  key.read();
  if (key.nextMode())
  {
    mode++;
    if (mode > 3)
    {
      mode = 1;
    }
  }

  if (key.powerOn())
  {
    if (key.lightOn())
    {
      mode = 0;
    }

    countDown = 255;

    if (mode == 0)
    {
      for (int iLED = 0; iLED < NUM_LEDS; iLED++)
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
    else if (mode == 1)
    {
      leds.fadeToBlackBy(50);
      for (int iLED = startPos; iLED < startPos + 4; iLED++)
      {
        leds[iLED].r = 255;
      }
      for (int iLED = NUM_LEDS - 1 - startPos; iLED > NUM_LEDS - 1 - startPos - 4; iLED--)
      {
        leds[iLED].b = 255;
      }
      if (up)
      {
        startPos++;
        if (startPos >= NUM_LEDS - 4)
        {
          startPos = NUM_LEDS - 4;
          up = false;
        }
      }
      else
      {
        startPos--;
        if (startPos <= 0)
        {
          startPos = 0;
          up = true;
        }
      }
    }
    else if (mode == 2)
    {
      rainbow.animate();
    }
    else if (mode == 3)
    {
      int iLED = random(NUM_LEDS);
      leds.fadeToBlackBy(40);
      leds[iLED].setRGB(180, 0, 180);
    }

    FastLED.show();
  }
  else
  {
    if (countDown > 0)
    {
      leds.fadeToBlackBy(1);
      countDown--;
      FastLED.show();
    }
  }

  delay(20);
}
