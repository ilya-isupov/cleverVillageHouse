#ifndef AirResistTemperatureSensor_h
#define AirResistTemperatureSensor_h

#include "AbstractTemperatureSensor.h"

class AirResistTemperatureSensor : public AbstractTemperatureSensor {
    AirResistTemperatureSensor();
    ~AirResistTemperatureSensor();

    void setup();
    void run();
};

#endif