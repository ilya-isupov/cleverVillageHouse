#include "DiodLamp.h"

DiodLamp::DiodLamp(uint8_t pin) : AbstractLamp(pin){};
DiodLamp::~DiodLamp(){}
void DiodLamp::setup() {
    AbstractLamp::setup();
}
void DiodLamp::lightOn()
{
    digitalWrite(unitPin, HIGH);
}

void DiodLamp::lightOff()
{
    digitalWrite(unitPin, LOW);
}