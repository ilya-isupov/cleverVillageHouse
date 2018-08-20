#include "Arduino.h"

class HardwareUnit {
    public:
        HardwareUnit() {};
        HardwareUnit(unsigned int pin, int mode) {
            this->setPinMode(pin, mode);
        };
        ~HardwareUnit() {}

        void setPinMode(unsigned int pin, int mode) {
            this->pinMode = mode;
            this->pin = pin;
            Arduino_h::pinMode(pin, mode);
        } 
    protected:
        unsigned int pin;
        int pinMode;        

};