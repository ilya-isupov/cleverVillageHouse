#ifndef Click_Button_h
#define Click_Button_h

#include "ClickButton.h"

template <class U>
class PressButton : public ClickButton<U>
{
    
  public:
    PressButton(byte pin, U *createContext);
    ~PressButton();
    void setup();
    void run();
    

};

#endif