#include "EEPROM.h"

class EepromController {
    
    public:
        static void write(int adr, uint8_t value);
        static void update(int adr, uint8_t value);
        static uint8_t read(int adr);
};