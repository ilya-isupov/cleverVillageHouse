#include "AbstractAirSensor.h"
AbstractAirSensor::AbstractAirSensor(uint8_t pin) : SimpleHardwareUnit(pin, INPUT) {}
AbstractAirSensor::~AbstractAirSensor() {}
void AbstractAirSensor::setup() {
    SimpleHardwareUnit::setup();
}

void AbstractAirSensor::run() {
    SimpleHardwareUnit::run();
}
