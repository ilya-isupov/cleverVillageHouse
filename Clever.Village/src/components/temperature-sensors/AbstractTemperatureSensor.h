#ifndef Abstract_Temperature_Sensor_H
#define Abstract_Temperature_Sensor_H

#include "../common/SimpleHardwareUnit.h"


class AbstractTemperatureSensor : public SimpleHardwareUnit {
    public:
        AbstractTemperatureSensor();
        AbstractTemperatureSensor(unsigned int pin);
        ~AbstractTemperatureSensor();
        void setup();
        void run();

};

#endif