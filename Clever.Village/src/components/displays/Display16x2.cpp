#include "Display16x2.h"

    Display16x2::Display16x2(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) {
        
    }

    LiquidMenu Display16x2::getLCD() {
        return lcd();
    }