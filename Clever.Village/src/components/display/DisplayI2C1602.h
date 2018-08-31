#include "AbsrtactDisplay.h"
#include <LiquidMenu.h>

class DisplayI2C1602 : public AbstractDisplay {
    public:
        DisplayI2C1602();
        DisplayI2C1602(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
        ~DisplayI2C1602();
        LiquidMenu getLCD();
        void setup();
        void setCursor();
        void print();
        void clear();

    private:
    LiquidMenu lcd();
};