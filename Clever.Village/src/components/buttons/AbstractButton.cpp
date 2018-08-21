#ifndef Abstract_Button_cpp
#define Abstract_Button_cpp

#include "../common/HardwareUnit.cpp"

class AbstractButton : HardwareUnit {
    public:
        AbstractButton() {};
        AbstractButton(unsigned int pin, int mode) {
            HardwareUnit(pin, mode);
        };
        ~AbstractButton() {};
              
};

#endif