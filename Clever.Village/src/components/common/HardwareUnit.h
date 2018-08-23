#ifndef HardwareUnit_h
#define HardwareUnit_h

#include "Arduino.h"

class HardwareUnit
{
public:
  HardwareUnit();
  HardwareUnit(unsigned int pin, int mode);
  ~HardwareUnit();

  virtual void setup();
  virtual void run();

protected:
  void setPinMode(unsigned int pin, int mode);
  unsigned int pin;;
  int pinWorkMode;
};
#endif