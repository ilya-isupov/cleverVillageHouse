#include "SimpleHardwareUnit.h"

SimpleHardwareUnit::SimpleHardwareUnit() : HardwareUnit() {};
SimpleHardwareUnit::SimpleHardwareUnit(unsigned int pin, int mode) {
    setPinMode(pin, mode);
};
SimpleHardwareUnit::~SimpleHardwareUnit() {};

void SimpleHardwareUnit::run() {
    HardwareUnit::run();
};

void SimpleHardwareUnit::setup() {
    HardwareUnit::setup();
    pinMode(pin, pinWorkMode);
}

void SimpleHardwareUnit::setPinMode(unsigned int pin, int mode)
{
    pinWorkMode = mode;
    pin = pin;
};