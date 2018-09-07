#ifndef Simple_Hardware_Unit_h
#define Simple_Hardware_Unit_h

#include "HardwareUnit.h"

class SimpleHardwareUnit : public HardwareUnit
{
  public:
    SimpleHardwareUnit(uint8_t pin, uint8_t mode);
    ~SimpleHardwareUnit();

    void setPinMode(uint8_t pin, uint8_t mode);
    virtual void setup();
    virtual void run();

  protected:
    uint8_t unitPin;
    uint8_t unitPinMode;
};

#endif