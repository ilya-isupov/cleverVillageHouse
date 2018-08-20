#include "AbstractButton.cpp"

class ClickButton : AbstractButton {
    public:
        ClickButton();
        ClickButton(unsigned int pin, int mode) {
            AbstractButton(pin, mode);
        };
        ~ClickButton();
};