
#ifndef Blower_h
#define Blower_h

#include "../common/SimpleHardwareUnit.h"

class Blower : public SimpleHardwareUnit {

    public: 
        Blower(unsigned int pin);
        Blower();
        ~Blower();
        void setMode(bool value);
    private:
        unsigned int pin;

};
#endif    