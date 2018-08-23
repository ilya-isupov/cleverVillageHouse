#ifndef Click_Button_h
#define Click_Button_h

#include "AbstractButton.h"

class ClickButton : public AbstractButton
{
    
    bool state;   
    bool isPressing;   
    bool isReleased;   
    bool isClicked;   
    bool isHolding;   

    #define holdTime 500           
    #define debounceTime 80        
    unsigned long lastTimeReleased; 
    void checkDebounce();
    void checkHoldReleased();
    void checkHeld();
    unsigned long getIdleTime();
  public:
    ClickButton();
    ClickButton(unsigned int pint, int mode);
    ~ClickButton();
    void setup();
    void run();

    bool wasClicked();
    bool wasHold();
};

#endif