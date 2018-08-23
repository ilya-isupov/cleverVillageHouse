#ifndef Click_Button_h
#define Click_Button_h

#include "AbstractButton.h"

class ClickButton : public AbstractButton
{
    unsigned int pin;
	int mode;
    
    boolean isState;   // храним состояния кнопок (S - State)
    boolean isPressing;   // флажки кнопок (F - Flag)
    boolean isReleased;   // флажки кнопок на отпускание (R - Release)
    boolean isPress;   // флажки кнопок на нажатие (P - Press)
    boolean isHold;   // флажки кнопок на удержание (многократный вызов) (H - Hold)

    #define doubletimer 100   // время (мс), отведённое на второе нажатие
    #define hold 500           // время (мс), после которого кнопка считается зажатой
    #define debounce 80        // (мс), антидребезг
    unsigned long lastTimeReleased; // таймер последнего нажатия кнопки
    unsigned long timeDouble; // таймер двойного нажатия кнопки

    void buttonDeBounce();
    void buttonBeforeHold();
    void buttonAfterDoubleTimer();
    void buttonAfterHold();
  public:
    ClickButton();
    ClickButton(unsigned int pint, int mode);
    ~ClickButton();
    void setup();
    void run();

    boolean isClickButtonOnce();
    boolean isHoldButton();
};

#endif