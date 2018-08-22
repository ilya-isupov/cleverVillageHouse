#ifndef Abstract_Button_cpp
#define Abstract_Button_cpp

#include "../common/HardwareUnit.cpp"

class AbstractButton : public HardwareUnit
{
  public:
    AbstractButton() : HardwareUnit(){};
    AbstractButton(unsigned int pin, int mode) : HardwareUnit(pin, mode){};
    ~AbstractButton(){};
    inline virtual void onClick(){};
    inline virtual void onHold(){};
    void run();
};

#endif