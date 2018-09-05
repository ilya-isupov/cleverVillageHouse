#ifndef HardwareUnit_h
#define HardwareUnit_h

#include "Arduino.h"

class HardwareUnit
{
public:
  HardwareUnit();
  ~HardwareUnit();

  virtual void setup();
  virtual void run();
  
};
#endif