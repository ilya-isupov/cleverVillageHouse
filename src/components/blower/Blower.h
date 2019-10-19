
#ifndef Blower_h
#define Blower_h

#include "../common/SimpleHardwareUnit.h"

class Blower : public SimpleHardwareUnit {

    public: 
        Blower(uint8_t pin);
        Blower();
        ~Blower();
        void setMode(bool value);

};
#endif    