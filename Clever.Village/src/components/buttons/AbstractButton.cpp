#ifndef Abstract_Button_cpp
#define Abstract_Button_cpp

#include "../common/HardwareUnit.cpp"

class AbstractButton : public HardwareUnit {
    public:
        AbstractButton() : HardwareUnit() {};
        AbstractButton(unsigned int pin, int mode) : HardwareUnit(pin, mode) {};
        ~AbstractButton() {};
              
};

#endif