#ifndef Click_Button_h
#define Click_Button_h

#include "AbstractButton.h"

class ClickButton : public AbstractButton
{
    unsigned int pin;
	int mode;
    
    boolean button1S;   // храним состояния кнопок (S - State)
    boolean button1F;   // флажки кнопок (F - Flag)
    boolean button1R;   // флажки кнопок на отпускание (R - Release)
    boolean button1P;   // флажки кнопок на нажатие (P - Press)
    boolean button1H;   // флажки кнопок на удержание (многократный вызов) (H - Hold)
    boolean button1HO;  // флажки кнопок на удержание (один вызов при нажатии) (HO - Hold Once)
    boolean button1D;   // флажки кнопок на двойное нажатие (D - Double)
    boolean button1DP;  // флажки кнопок на двойное нажатие и отпускание (D - Double Pressed)

    #define double_timer 100   // время (мс), отведённое на второе нажатие
    #define hold 500           // время (мс), после которого кнопка считается зажатой
    #define debounce 80        // (мс), антидребезг
    unsigned long button1_timer; // таймер последнего нажатия кнопки
    unsigned long button1_double; // таймер двойного нажатия кнопки

  public:
    ClickButton();
    ClickButton(unsigned int pint, int mode);
    ~ClickButton();
    void setup();
    void run();

    boolean ClickButtonOnce();
    boolean HoldButton();
};

#endif