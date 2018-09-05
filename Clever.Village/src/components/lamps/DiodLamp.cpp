#include "DiodLamp.h"

DiodLamp::DiodLamp(unsigned int pin) : AbstractLamp(pin){};
DiodLamp::~DiodLamp(){}
void DiodLamp::setup() {
    AbstractLamp::setup();
}
void DiodLamp::lightOn()
{
    digitalWrite(pin, HIGH);
}

void DiodLamp::lightOff()
{
    digitalWrite(pin, LOW);
}