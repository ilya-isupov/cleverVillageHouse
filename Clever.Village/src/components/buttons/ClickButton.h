#ifndef Click_Button_h
#define Click_Button_h

#include "AbstractButton.h"

class ClickButton : public AbstractButton
{
    
    boolean state;   // храним состояния кнопок (S - State)
    boolean isPressing;   // флажки кнопок (F - Flag)
    boolean isReleased;   // флажки кнопок на отпускание (R - Release)
    boolean isClicked;   // флажки кнопок на нажатие (P - Press)
    boolean isHolding;   // флажки кнопок на удержание (многократный вызов) (H - Hold)

    #define holdTime 500           // время (мс), после которого кнопка считается зажатой
    #define debounceTime 80        // (мс), антидребезг
    unsigned long lastTimeReleased; // таймер последнего нажатия кнопки
    void checkDebounce();
    void checkHoldReleased();
    void checkHeld();
  public:
    ClickButton();
    ClickButton(unsigned int pint, int mode);
    ~ClickButton();
    void setup();
    void run();

    boolean wasClicked();
    boolean wasHold();
};

#endif