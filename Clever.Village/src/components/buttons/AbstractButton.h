#ifndef Abstract_Button_h
#define Abstract_Button_h

#include "../common/HardwareUnit.h"

class AbstractButton : public HardwareUnit
{
  public:
    AbstractButton();
    AbstractButton(unsigned int pin, int mode);
    ~AbstractButton();
    inline virtual void onClick();
    inline virtual void onHold();
    virtual void run();
    virtual void setup();
};

#endif