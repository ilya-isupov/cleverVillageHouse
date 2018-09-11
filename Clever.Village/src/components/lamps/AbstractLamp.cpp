#include "AbstractLamp.h"

AbstractLamp::AbstractLamp(uint8_t pin) : SimpleHardwareUnit(pin, OUTPUT){};
AbstractLamp::~AbstractLamp(){};
void AbstractLamp::setup() {
    SimpleHardwareUnit::setup();
};
void AbstractLamp::lightOff(){
    
};
void AbstractLamp::lightOn(){};