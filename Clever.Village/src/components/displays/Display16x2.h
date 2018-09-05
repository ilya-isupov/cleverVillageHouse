#include "AbsrtactDisplay.h"
#include <LiquidMenu.h>

class Display16x2 : public AbstractDisplay {
    public:
        Display16x2();
        Display16x2(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
        ~Display16x2();
        LiquidMenu getLCD();
        void setup();
        void setCursor();
        void print();
        void clear();

    private:
    LiquidMenu lcd();
};