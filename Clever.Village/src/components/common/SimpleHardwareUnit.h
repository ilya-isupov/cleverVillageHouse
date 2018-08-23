#ifndef Simple_Hardware_Unit_h
#define Simple_Hardware_Unit_h

#include "HardwareUnit.h"

class SimpleHardwareUnit : public HardwareUnit
{
  public:
    SimpleHardwareUnit();
    SimpleHardwareUnit(unsigned int pin, int mode);
    ~SimpleHardwareUnit();

    void setPinMode(unsigned int pin, int mode);
    virtual void setup();
    virtual void run();

  protected:
    unsigned int pin;
    int pinWorkMode;
};

#endif