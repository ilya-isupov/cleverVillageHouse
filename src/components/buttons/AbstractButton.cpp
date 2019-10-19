#include "AbstractButton.h"

AbstractButton::AbstractButton(uint8_t pin) : SimpleHardwareUnit(pin, INPUT_PULLUP){};
AbstractButton::~AbstractButton(){};
void AbstractButton::run() {}
void AbstractButton::setup() {
    SimpleHardwareUnit::setup();
}