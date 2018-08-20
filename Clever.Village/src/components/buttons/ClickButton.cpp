#include "AbstractButton.cpp"

class ClickButton : AbstractButton {
    public:
        ClickButton(unsigned int pin, int mode);
        ~ClickButton();
};