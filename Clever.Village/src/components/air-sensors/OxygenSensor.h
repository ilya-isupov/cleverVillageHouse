#ifndef Oxygen_Sensor_cpp
#define Oxygen_Sensor_cpp

#include "AbstractAirSensor.cpp"

class OxygenSensor : public AbstractAirSensor {
    public:
        OxygenSensor() : AbstractAirSensor() {};
        OxygenSensor(unsigned int pin, int mode) : AbstractAirSensor(pin) {};
        ~OxygenSensor() {};
    private:
};

#endif