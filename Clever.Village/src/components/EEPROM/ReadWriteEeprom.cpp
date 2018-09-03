#include "ReadWriteEeprom.h"


void ReadWriteEeprom::write(int adr, uint8_t value) {
    EEPROM.write(adr, value);
}

uint8_t ReadWriteEeprom::read(int adr) {
    EEPROM.read(adr);
}
void ReadWriteEeprom::update(int adr, uint8_t value) {
    EEPROM.update(adr, value);
}