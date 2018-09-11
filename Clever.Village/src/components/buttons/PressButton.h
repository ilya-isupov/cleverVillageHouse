#ifndef PRESSBUTTON_H
#define PRESSBUTTON_H

#include "ClickButton.h"

template <class U>
class PressButton : public ClickButton<U>
{

public:
  PressButton(byte pin, U *createContext) : ClickButton<U>(pin, true, createContext) {}
  ~PressButton(){};
  void setup(){};
  void run(){};
};

#endif