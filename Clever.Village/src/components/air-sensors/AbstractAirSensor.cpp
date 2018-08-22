#ifndef Abstract_Air_Sensor_cpp
#define Abstract_Air_Sensor_cpp

#include "../common/HardwareUnit.cpp"

class AbstractAirSensor : HardwareUnit {
    public:
        AbstractAirSensor() {};
        AbstractAirSensor(unsigned int pin, int mode) : HardwareUnit(pin, mode) {};
        ~AbstractAirSensor() {};
};

#endif