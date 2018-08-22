#ifndef Abstract_Air_Sensor_cpp
#define Abstract_Air_Sensor_cpp

#include "../common/HardwareUnit.h"

class AbstractAirSensor : public HardwareUnit {
    public:
        AbstractAirSensor() : HardwareUnit() {};
        AbstractAirSensor(unsigned int pin, int mode) : HardwareUnit(pin, mode) {};
        ~AbstractAirSensor() {};
};

#endif