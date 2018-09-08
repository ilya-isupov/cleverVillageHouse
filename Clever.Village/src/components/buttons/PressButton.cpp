#include "PressButton.h"

template <class U>
PressButton<U>::PressButton(byte pin, U *createContext) : ClickButton<U>(pin, true, createContext){};

template <class U>
PressButton<U>::~PressButton(){};

template <class U>
void PressButton<U>::setup(){};

template <class U>
void PressButton<U>::run() {};
