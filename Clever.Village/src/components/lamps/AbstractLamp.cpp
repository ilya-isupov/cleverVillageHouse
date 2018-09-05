#include "AbstractLamp.h"

AbstractLamp::AbstractLamp(unsigned int pin) : SimpleHardwareUnit(pin, OUTPUT){};
AbstractLamp::~AbstractLamp(){};
void AbstractLamp::setup() {
    SimpleHardwareUnit::setup();
};