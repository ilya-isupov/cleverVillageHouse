#include "AbstractButton.h"

AbstractButton::AbstractButton() : SimpleHardwareUnit(){};
AbstractButton::AbstractButton(unsigned int pin) : SimpleHardwareUnit(pin, INPUT_PULLUP){};
AbstractButton::~AbstractButton(){};
void AbstractButton::run() {}
void AbstractButton::setup() {}