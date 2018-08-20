#include "AbstractButton.h"

AbstractButton::AbstractButton() {}
AbstractButton::~AbstractButton() {}

void AbstractButton::setPin(byte pin, int mode) {
    hardwarePinMode = mode;
    hardwarePinNumber = pin;
    pinMode(hardwarePinNumber, hardwarePinMode);
}