#ifndef Click_Button_cpp
#define Click_Button_cpp

#include "AbstractButton.cpp"

class ClickButton : AbstractButton {
    public:
        ClickButton() {};
        ClickButton(unsigned int pin, int mode) {
            AbstractButton(pin, mode);
        };
        ~ClickButton();
};

#endif