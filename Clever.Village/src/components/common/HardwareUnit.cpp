#include "HardwareUnit.h"

HardwareUnit::HardwareUnit() {}
HardwareUnit::~HardwareUnit() {}
HardwareUnit::HardwareUnit(unsigned int pin, int mode)
{
    this->setPinMode(pin, mode);
};

void HardwareUnit::run() {}
void HardwareUnit::setup() {}

void HardwareUnit::setPinMode(unsigned int pin, int mode)
{
    this->pinWorkMode = mode;
    this->pin = pin;
    pinMode(pin, mode);
};