#ifndef KEY_H
#define HEY_H

class Key
{
  public:
    Key(int pin);
    void read();
    bool powerOn();
    bool nextMode();
    bool lightOn();

  private:
    int keyPin;

    int pushCount;  // counter for read cycles while the button is pressed
    int shortCount;  // count of short pushes in series
    int delayCount;  // count of read cycles between short pushes
    int cycleCount;

    bool powerState;
    bool cycle;
    bool autoCycle;
    bool light;
};

#endif
