#ifndef Click_Button_h
#define Click_Button_h

#include "AbstractButton.h"

class ClickButton : public AbstractButton
{
    unsigned int pin;
	int mode;
    unsigned long last_press;

  public:
    ClickButton();
    ClickButton(unsigned int pint, int mode);
    ~ClickButton();

    boolean ClickButtonOnce();
    boolean HoldButton();
};

#endif