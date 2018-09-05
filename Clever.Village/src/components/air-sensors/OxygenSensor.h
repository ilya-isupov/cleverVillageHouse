#ifndef OXYGENSENSOR_H
#define OXYGENSENSOR_H

#include "AbstractAirSensor.h"

class OxygenSensor : public AbstractAirSensor {
    public:
        OxygenSensor(unsigned int pin);
        ~OxygenSensor();
    private:
};

#endif