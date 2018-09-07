#ifndef Click_Button_h
#define Click_Button_h

#include "OneButton.h"

class PressButton : public OneButton
{
    
  public:
    PressButton(uint8_t pin);
    ~PressButton();
    void setup();
    void run();
    

};

#endif