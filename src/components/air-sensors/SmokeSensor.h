#ifndef Smoke_Sensor_cpp
#define Smoke_Sensor_cpp

#include "AbstractAirSensor.cpp"

class SmokeSensor : public AbstractAirSensor {
    public:
        SmokeSensor() : AbstractAirSensor() {};
        SmokeSensor(unsigned int pin, int mode) : AbstractAirSensor(pin) {};
        ~SmokeSensor() {};
};

#endif