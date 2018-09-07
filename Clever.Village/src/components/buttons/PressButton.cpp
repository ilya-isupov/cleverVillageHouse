#include "PressButton.h"

template <class U>
PressButton<U>::PressButton(uint8_t pin, U *createContext) : ClickButton<U>(pin, true, createContext){};
template <class U>
PressButton<U>::~PressButton(){};

template <class U>
void PressButton<U>::setup(){};

template <class U>
void PressButton<U>::run() {};
