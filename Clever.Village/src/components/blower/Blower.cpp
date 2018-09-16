#include "Blower.h"


void Blower::setMode(bool value) {
    digitalWrite(unitPin, value);
}