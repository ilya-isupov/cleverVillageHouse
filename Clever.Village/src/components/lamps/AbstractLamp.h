#ifndef ABSTRACTLAMP_H
#define ABSTRACTLAMP_H

#include "../common/SimpleHardwareUnit.h"

class AbstractLamp : public SimpleHardwareUnit
{
  public:
    AbstractLamp(unsigned int pin);
    ~AbstractLamp();
    void setup();
    virtual void lightOn();
    virtual void lightOff();
};

#endif