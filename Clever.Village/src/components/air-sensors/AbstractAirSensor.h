#ifndef Abstract_Air_Sensor_cpp
#define Abstract_Air_Sensor_cpp

#include "../common/SimpleHardwareUnit.h"

class AbstractAirSensor : public SimpleHardwareUnit {
    public:
        AbstractAirSensor(unsigned int pin) : SimpleHardwareUnit(pin, INPUT) {};
        ~AbstractAirSensor() {};
};

#endif