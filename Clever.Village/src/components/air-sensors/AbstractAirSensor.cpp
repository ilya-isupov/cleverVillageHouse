

#include "AbstractAirSensor.h"

class AbstractAirSensor : public SimpleHardwareUnit {
    public:
        AbstractAirSensor() : SimpleHardwareUnit() {};
        AbstractAirSensor(unsigned int pin) : SimpleHardwareUnit(pin, INPUT) {};
        ~AbstractAirSensor() {};
};
