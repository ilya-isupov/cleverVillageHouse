#ifndef Click_Button_cpp
#define Click_Button_cpp

#include "AbstractButton.cpp"

class ClickButton : public AbstractButton
{
    unsigned int pin;
	int mode;
    unsigned long last_press;

  public:
    ClickButton() : AbstractButton() {};
    ClickButton(unsigned int pint, int mode) : AbstractButton(pin, mode){};
    ~ClickButton();

    boolean ClickButtonOnce(){};

    boolean HoldButton(){};
};

#endif