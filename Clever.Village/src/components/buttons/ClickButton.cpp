#include "ClickButton.h"

    ClickButton::ClickButton() : AbstractButton() {};
    ClickButton::ClickButton(unsigned int pin, int mode) : AbstractButton(pin, mode){
        
	};
    ClickButton::~ClickButton() {};

    void ClickButton::setup() {
      
    }
    unsigned long ClickButton::getIdleTime() {
      return  millis() - lastTimeReleased;
    }
    void ClickButton::checkDebounce() {
  if (state && !isPressing && ClickButton::getIdleTime() > debounceTime) {
    isPressing = 1;
    lastTimeReleased = millis();
      }
    }
    void ClickButton::checkHoldReleased() {
      if (!state && isPressing && !isReleased && ClickButton::getIdleTime() < holdTime) {
        isReleased = 1;
        isPressing = 0;
      }
    }
    void ClickButton::checkHeld() {    
  if (isPressing && !isHolding && ClickButton::getIdleTime() > holdTime) {
    isHolding = 1;
  }
  if (!state && isPressing && ClickButton::getIdleTime() > holdTime) {
    isPressing = 0;
    isHolding = 0;
    lastTimeReleased = millis();
  }
    }
    void ClickButton::run() {
      state = !digitalRead(pin);
     ClickButton::checkDebounce();
     ClickButton::checkHoldReleased(); 
     ClickButton::checkHeld(); 
    }
    bool ClickButton::wasClicked()
    {

		if (isClicked) {
            isClicked = 0;
           return true;
        } else 
        return false;
    }

    bool ClickButton::wasHold()
    {
		if (isHolding) {
            isHolding = 0;
            return true;
        } else 
        return false;
    }