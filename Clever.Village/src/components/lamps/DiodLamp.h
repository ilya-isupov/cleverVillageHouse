#ifndef DIODLAMP_H
#define DIODLAMP_H

#include "AbstractLamp.h"

class DiodLamp : public AbstractLamp
{
  public:
    DiodLamp(unsigned int pin);
    void setup();
    virtual void lightOn();
    virtual void lightOff();
    ~DiodLamp();
};

#endif