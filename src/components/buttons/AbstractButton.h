#ifndef Abstract_Button_h
#define Abstract_Button_h

#include "../common/SimpleHardwareUnit.h"

class AbstractButton : public SimpleHardwareUnit
{
  public:
    AbstractButton(uint8_t pin);
    ~AbstractButton();
    virtual void run();
    virtual void setup();
};

#endif