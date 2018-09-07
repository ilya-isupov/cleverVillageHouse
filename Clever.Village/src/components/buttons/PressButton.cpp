#include "PressButton.h"

PressButton::PressButton(uint8_t pin) : OneButton(pin, true){};
PressButton::~PressButton(){};

void PressButton::setup(){}
void PressButton::run() {}
