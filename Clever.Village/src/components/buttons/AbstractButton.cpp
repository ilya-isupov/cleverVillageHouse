#include "Arduino.h"


class AbstractButton {
    public:
        AbstractButton(unsigned int pin, int mode) {
            this->setPinMode(pin, mode);
        };
        ~AbstractButton();
        void setPinMode(unsigned int pin, int mode) {
            this->pinMode = mode;
            this->pin = pin;
            Arduino_h::pinMode(pin, mode);
        }
    
    private:
        unsigned int pin;
        int pinMode;        
};