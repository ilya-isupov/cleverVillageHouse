#ifndef HardwareUnit_h
#define HardwareUnit_h

#include "Arduino.h"

class HardwareUnit
{
  public:
    HardwareUnit();
    HardwareUnit(unsigned int pin, int mode);
    ~HardwareUnit();

    void setPinMode(unsigned int pin, int mode);

  protected:
    unsigned int pin;
    int pinMode;
};
#endif