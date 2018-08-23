#include "ClickButton.h"

    ClickButton::ClickButton() : AbstractButton() {};
    ClickButton::ClickButton(unsigned int pin, int mode) : AbstractButton(pin, mode){
        //
	};
    ClickButton::~ClickButton() {};

    void ClickButton::setup() {
       // 
    }
    void ClickButton::checkDebounce() {
  if (state && !isPressing && millis() - lastTimeReleased > debounceTime) {
    isPressing = 1;
    lastTimeReleased = millis();
      }
    }
    void ClickButton::checkHoldReleased() {
      if (!state && isPressing && !isReleased && millis() - lastTimeReleased < holdTime) {
        isReleased = 1;
        isPressing = 0;
      }
    }
    void ClickButton::checkHeld() {
        // Если удерживается более hold, то считать удержанием
  if (isPressing && !isHolding && millis() - lastTimeReleased > holdTime) {
    isHolding = 1;
  }
  // Если отпущена после hold, то считать, что была удержана
  if (!state && isPressing && millis() - lastTimeReleased > holdTime) {
    isPressing = 0;
    isHolding = 0;
    lastTimeReleased = millis();
  }
    }
    void ClickButton::run() {
      state = !digitalRead(pin);
     ClickButton::checkDebounce(); // нажали (с антидребезгом)
     ClickButton::checkHoldReleased(); // если отпустили до hold, считать отпущенной
     ClickButton::checkHeld(); // после удержания
    }
    boolean ClickButton::wasClicked()
    {
	//	boolean res;
		if (isClicked) {
            isClicked = 0;
           // res = true;
           return true;
        } else 
       // res = false;
        return false;
    }

    boolean ClickButton::wasHold()
    {
       // boolean res;
		if (isHolding) {
            isHolding = 0;
            //res = true;
            return true;
        } else 
       // res = false;
        return false;
    }