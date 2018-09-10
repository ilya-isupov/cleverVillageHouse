#include "EepromController.h"


void EepromController::write(int adr, uint8_t value) {
    EEPROM.write(adr, value);
}

uint8_t EepromController::read(int adr) {
    return EEPROM.read(adr);
}
void EepromController::update(int adr, uint8_t value) {
    EEPROM.update(adr, value);
}