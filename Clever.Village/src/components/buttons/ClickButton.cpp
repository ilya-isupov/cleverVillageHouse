#include "ClickButton.h"

    ClickButton::ClickButton() : AbstractButton() {};
    ClickButton::ClickButton(unsigned int pin, int mode) : AbstractButton(pin, mode){
        //
	};
    ClickButton::~ClickButton() {};

    void ClickButton::setup() {
        pinMode(pin, mode);
    }
    void ClickButton::buttonDeBounce() {
  if (button1S && !button1Flag && millis() - button1timer > debounce) {
    button1Flag = 1;
    button1HO = 1;
    button1timer = millis();
      }
    }
    void ClickButton::buttonBeforeHold() {
      if (!button1S && button1Flag && !button1Release && !button1DP && millis() - button1timer < hold) {
        button1Release = 1;
        button1Flag = 0;
        button1double = millis();
      }
    }
    void ClickButton::buttonAfterDoubleTimer() {
       if (button1Release && !button1DP && millis() - button1double > doubletimer) {
        button1Release = 0;
        button1Press = 1;
  }
    }
    void ClickButton::buttonAfterHold() {
        // Если удерживается более hold, то считать удержанием
  if (button1Flag && !buttonDouble && !button1Hold && millis() - button1timer > hold) {
    button1Hold = 1;
  }
  // Если отпущена после hold, то считать, что была удержана
  if (!button1S && button1Flag && millis() - button1timer > hold) {
    button1Flag = 0;
    button1Hold = 0;
    button1timer = millis();
  }
    }
    void ClickButton::run() {
      button1S = !digitalRead(pin);
     ClickButton::buttonDeBounce(); // нажали (с антидребезгом)
     ClickButton::buttonBeforeHold(); // если отпустили до hold, считать отпущенной
     ClickButton::buttonAfterDoubleTimer();  // если отпустили и прошло больше double_timer, считать 1 нажатием
     ClickButton::buttonAfterHold(); // после удержания
    }
    boolean ClickButton::isClickButtonOnce()
    {
		boolean res;
		if (button1Press) {
            button1Press = 0;
            res = true;
        } else 
        res = false;
        return res;
    }

    boolean ClickButton::isHoldButton()
    {
        boolean res;
		if (button1Hold) {
            button1Hold = 0;
            res = true;
        } else 
        res = false;
        return res;
    }