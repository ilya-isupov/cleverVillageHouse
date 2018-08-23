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
  if (isState && !isPressing && millis() - lastTimeReleased > debounce) {
    isPressing = 1;
    lastTimeReleased = millis();
      }
    }
    void ClickButton::buttonBeforeHold() {
      if (!isState && isPressing && !isReleased && millis() - lastTimeReleased < hold) {
        isReleased = 1;
        isPressing = 0;
        timeDouble = millis();
      }
    }
    void ClickButton::buttonAfterDoubleTimer() {
       if (isReleased && millis() - timeDouble > doubletimer) {
        isReleased = 0;
        isPress = 1;
  }
    }
    void ClickButton::buttonAfterHold() {
        // Если удерживается более hold, то считать удержанием
  if (isPressing && !isHold && millis() - lastTimeReleased > hold) {
    isHold = 1;
  }
  // Если отпущена после hold, то считать, что была удержана
  if (!isState && isPressing && millis() - lastTimeReleased > hold) {
    isPressing = 0;
    isHold = 0;
    lastTimeReleased = millis();
  }
    }
    void ClickButton::run() {
      isState = !digitalRead(pin);
     ClickButton::buttonDeBounce(); // нажали (с антидребезгом)
     ClickButton::buttonBeforeHold(); // если отпустили до hold, считать отпущенной
     ClickButton::buttonAfterDoubleTimer();  // если отпустили и прошло больше double_timer, считать 1 нажатием
     ClickButton::buttonAfterHold(); // после удержания
    }
    boolean ClickButton::isClickButtonOnce()
    {
		boolean res;
		if (isPress) {
            isPress = 0;
            res = true;
        } else 
        res = false;
        return res;
    }

    boolean ClickButton::isHoldButton()
    {
        boolean res;
		if (isHold) {
            isHold = 0;
            res = true;
        } else 
        res = false;
        return res;
    }