#include "ClickButton.h"

    ClickButton::ClickButton() : AbstractButton() {};
    ClickButton::ClickButton(unsigned int pint, int modet) : AbstractButton(pin, mode){
		pin = pint;
		mode = modet;
	};
    ClickButton::~ClickButton() {};

    void ClickButton::setup() {
        pinMode(pin, mode);
    }
    void ClickButton::run() {
      button1S = !digitalRead(pin);
     // нажали (с антидребезгом)
  if (button1S && !button1F && millis() - button1_timer > debounce) {
    button1F = 1;
    button1HO = 1;
    button1_timer = millis();
  }
  // если отпустили до hold, считать отпущенной
  if (!button1S && button1F && !button1R && !button1DP && millis() - button1_timer < hold) {
    button1R = 1;
    button1F = 0;
    button1_double = millis();
  }
  // если отпустили и прошло больше double_timer, считать 1 нажатием
  if (button1R && !button1DP && millis() - button1_double > double_timer) {
    button1R = 0;
    button1P = 1;
  }

  // Если удерживается более hold, то считать удержанием
  if (button1F && !button1D && !button1H && millis() - button1_timer > hold) {
    button1H = 1;
  }
  // Если отпущена после hold, то считать, что была удержана
  if (!button1S && button1F && millis() - button1_timer > hold) {
    button1F = 0;
    button1H = 0;
    button1_timer = millis();
  }
    }
    boolean ClickButton::ClickButtonOnce()
    {
		boolean res;
		if (button1P) {
            button1P = 0;
            res = true;
        } else 
        res = false;
        return res;
    }

    boolean ClickButton::HoldButton()
    {
        boolean res;
		if (button1H) {
            button1H = 0;
            res = true;
        } else 
        res = false;
        return res;
    }