#include "AbsrtactDisplay.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>

class Display16x2 : public AbstractDisplay {
    public:
        Display16x2();
        Display16x2(uint8_t rs,  uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
        Display16x2(int type, uint8_t a, uint8_t b);
        ~Display16x2();
        void setup();
        void setFirstLine(byte column, byte row, String value);
        void setSecondLine(byte column, byte row, String value);
        void setScreen();
        void update();
        void nextScreen();

    private:
        LiquidCrystal_I2C *lcd;
        LiquidMenu *displayMenu;
        LiquidLine *firstLine;
        LiquidLine *secondLine;
        LiquidScreen *screen;
};