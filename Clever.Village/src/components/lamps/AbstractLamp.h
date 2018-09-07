#ifndef ABSTRACTLAMP_H
#define ABSTRACTLAMP_H

#include "../common/SimpleHardwareUnit.h"

class AbstractLamp : public SimpleHardwareUnit
{
  public:
    AbstractLamp(uint8_t pin);
    ~AbstractLamp();
    void setup();
    void lightOn();
    void lightOff();
};

#endif