#include "DisplayI2C1602.h"

    DisplayI2C1602::DisplayI2C1602(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) {
        
    }

    LiquidMenu DisplayI2C1602::getLCD() {
        return lcd();
    }