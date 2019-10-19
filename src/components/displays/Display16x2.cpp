#include "Display16x2.h"

Display16x2::Display16x2() {
    this->lcd = new LiquidCrystal_I2C(0x42, 16, 2); 
    this->displayMenu = new LiquidMenu(*lcd);
}

Display16x2::Display16x2(int type, uint8_t a, uint8_t b) {
    this->lcd = new LiquidCrystal_I2C(type, a, b); 
    this->displayMenu = new LiquidMenu(*lcd);
}
void Display16x2::setup() {
    this->lcd->init();
    this->lcd->backlight();
    this->displayMenu->init();

}
void Display16x2::update() {
    this->displayMenu->update();
}
void Display16x2::setFirstLine(byte column, byte row, String value) {
    this->firstLine = new LiquidLine(column, row, value);
}
void Display16x2::setSecondLine(byte column, byte row, String value) {
    this->secondLine = new LiquidLine(column, row, value);
}
void Display16x2::setScreen() {
    this->screen = new LiquidScreen(*firstLine, *secondLine);
    this->displayMenu->add_screen(*screen);
}
void Display16x2::nextScreen() {
    this->displayMenu->next_screen();
}
