#ifndef EEPROMCONTROLLER_H
#define EEPROMCONTROLLER_H

#include "EEPROM.h"
#include "Arduino.h"

class EepromController {
    
    public:
        static const byte EMPTY_VALUE = 0xFF;

        static void write(int adr, uint8_t value);
        static void update(int adr, uint8_t value);
        static uint8_t read(int adr);
};

#endif