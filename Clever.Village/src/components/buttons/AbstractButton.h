#ifndef Abstract_Button_h
#define Abstract_Button_h

#include "../common/SimpleHardwareUnit.h"

class AbstractButton : public SimpleHardwareUnit
{
  public:
    AbstractButton();
    AbstractButton(unsigned int pin);
    ~AbstractButton();
    virtual bool wasClicked();
    virtual bool wasHold();
    virtual void run();
    virtual void setup();
};

#endif