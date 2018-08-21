#ifndef Oxygen_Sensor_cpp
#define Oxygen_Sensor_cpp

#include "AbstractAirSensor.cpp"

class OxygenSensor : AbstractAirSensor {
    public:
        OxygenSensor() {};
        OxygenSensor(unsigned int pin, int mode) {
            AbstractAirSensor(pin, mode);
        };
        ~OxygenSensor() {};
};

#endif