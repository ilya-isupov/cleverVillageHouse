#include "EEPROM.h"

class EepromController {
    
    public:
        void write(int adr, uint8_t value);
        void update(int adr, uint8_t value);
        uint8_t read(int adr);
};