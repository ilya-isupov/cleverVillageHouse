#ifndef DIODLAMP_H
#define DIODLAMP_H

#include "AbstractLamp.h"

class DiodLamp : public AbstractLamp
{
  public:
    DiodLamp(uint8_t pin);
    void setup();
    void lightOn();
    void lightOff();
    ~DiodLamp();
};

#endif