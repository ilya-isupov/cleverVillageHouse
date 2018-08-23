#ifndef Abstract_Temperature_Sensor_cpp
#define Abstract_Temperature_Sensor_cpp

#include "../common/SimpleHardwareUnit.h"

class AbstractTemperatureSensor : public SimpleHardwareUnit {
    public:
        AbstractTemperatureSensor() : SimpleHardwareUnit() {};
        AbstractTemperatureSensor(unsigned int pin) : SimpleHardwareUnit(pin, INPUT_PULLUP) {};
        ~AbstractTemperatureSensor() {};
};

#endif