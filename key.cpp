#include "key.h"
#include "Arduino.h"

Key::Key(int pin)
{
  pushCount = 0;
  powerState = true;
  shortCount = 0;
  delayCount = 0;
  cycle = false;
  autoCycle = false;
  cycleCount = 0;
  light = false;

  keyPin = pin;
  pinMode(keyPin, INPUT_PULLUP);
}

void Key::read()
{
  if (digitalRead(keyPin) == LOW)
  {
    pushCount++;
  }
  else
  {
    if (pushCount >= 5 && pushCount < 50)
    {
      shortCount++;
      delayCount = 0;
    }
    else if (pushCount >= 50)
    {
      powerState = !powerState;
    }

    // reset anyway
    pushCount = 0;

    // count delay
    delayCount++;
    if (delayCount > 50)
    {
      switch (shortCount)
      {
        case 1:
          cycle = true;
          break;
        case 2:
          autoCycle = !autoCycle;
          break;
        case 3:
          light = true;
          autoCycle = false;
          break;
        default:
          // nothing...
          break;
      }

      // reset shortCount
      shortCount = 0;
      delayCount = 0;
    }

    // autoCycle
    if (autoCycle)
    {
      cycleCount++;
      if (cycleCount > 2000)
      {
        cycle = true;
        cycleCount = 0;
      }
    }

  }
}

bool Key::powerOn()
{
  return powerState;
}

bool Key::nextMode()
{
  if (cycle)
  {
    cycle = false;
    return true;
  }

  return false;
}

bool Key::lightOn()
{
  if (light)
  {
    light = false;
    return true;
  }
  return false;
}

