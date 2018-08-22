#include "HardwareUnit.h"

HardwareUnit::HardwareUnit() {}
HardwareUnit::~HardwareUnit() {}
HardwareUnit::HardwareUnit(unsigned int pin, int mode)
{
    this->setPinMode(pin, mode);
};

void HardwareUnit::setPinMode(unsigned int pin, int mode)
{
    this->pinMode = mode;
    this->pin = pin;
    Arduino_h::pinMode(pin, mode);
};