#ifndef Click_Button_h
#define Click_Button_h

#include "AbstractButton.h"

class ClickButton : public AbstractButton
{
    unsigned int pin;
	int mode;
    
    boolean button1S;   // храним состояния кнопок (S - State)
    boolean button1Flag;   // флажки кнопок (F - Flag)
    boolean button1Release;   // флажки кнопок на отпускание (R - Release)
    boolean button1Press;   // флажки кнопок на нажатие (P - Press)
    boolean button1Hold;   // флажки кнопок на удержание (многократный вызов) (H - Hold)
    boolean button1HO;  // флажки кнопок на удержание (один вызов при нажатии) (HO - Hold Once)
    boolean buttonDouble;   // флажки кнопок на двойное нажатие (D - Double)
    boolean button1DP;  // флажки кнопок на двойное нажатие и отпускание (D - Double Pressed)

    #define doubletimer 100   // время (мс), отведённое на второе нажатие
    #define hold 500           // время (мс), после которого кнопка считается зажатой
    #define debounce 80        // (мс), антидребезг
    unsigned long button1timer; // таймер последнего нажатия кнопки
    unsigned long button1double; // таймер двойного нажатия кнопки

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