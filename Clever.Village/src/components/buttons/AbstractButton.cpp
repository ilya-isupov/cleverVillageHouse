#include "AbstractButton.h"

AbstractButton::AbstractButton() : HardwareUnit(){};
AbstractButton::AbstractButton(unsigned int pin, int mode) : HardwareUnit(pin, mode){};
AbstractButton::~AbstractButton(){};
void AbstractButton::run() {}
void AbstractButton::setup() {}