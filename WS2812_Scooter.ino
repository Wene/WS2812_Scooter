#include "FastLED.h"
#include "key.h"
#include "rainbow.h"
#include "sparkling.h"
#include "police.h"
#include "streetlight.h"
#include "colorsnow.h"
#include "crossing.h"
#include "bubbles.h"
#include "rainbowsparkle.h"

// define the number of LEDs
#define NUM_LEDS 60

// define the pins
#define LED_PIN 10
#define BTN_PIN 11

Key key(BTN_PIN);

CRGBArray<NUM_LEDS> leds;

// initiate all my animations objects
Rainbow rainbow(leds, NUM_LEDS);
Sparkling sparkling(leds, NUM_LEDS);
Police police(leds, NUM_LEDS);
StreetLight streetlight(leds, NUM_LEDS);
ColorSnow colorsnow(leds, NUM_LEDS);
Crossing crossing(leds, NUM_LEDS);
Bubbles bubbles(leds, NUM_LEDS);
RainbowSparkle rainbowsparkle(leds, NUM_LEDS);

void setup() {
  //setting maximum brightness
  FastLED.setBrightness(80);

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  //GRB for the WS2812 color order

  //reset all the LEDs
  leds.nscale8(0);
  FastLED.show();

  // initialize random renerator with true random value (hopefully)
  randomSeed(analogRead(A2));

  pinMode(LED_BUILTIN, OUTPUT);

}

int mode = 1;
uint8_t countDown = 255;

bool statusIndicator = true;

void loop()
{
  key.read();
  if (key.nextMode())
  {
    mode++;
    if (mode > 7)
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

    switch (mode)
    {
      case 0:
        streetlight.animate();
        break;
      case 1:
        sparkling.animate();
        break;
      case 2:
        rainbow.animate();
        break;
      case 3:
        police.animate();
        break;
      case 4:
        colorsnow.animate();
        break;
      case 5:
        crossing.animate();
        break;
      case 6:
        bubbles.animate();
        break;
      case 7:
        rainbowsparkle.animate();
        break;
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

  statusIndicator = !statusIndicator;
  digitalWrite(LED_BUILTIN, statusIndicator);

  delay(20);
}
