#ifndef Abstract_Temperature_Sensor_cpp
#define Abstract_Temperature_Sensor_cpp

#include "../common/HardwareUnit.cpp"

class AbstractTemperatureSensor : public HardwareUnit {
    public:
        AbstractTemperatureSensor() : HardwareUnit() {};
        AbstractTemperatureSensor(unsigned int pin, int mode) : HardwareUnit(pin, mode) {};
        ~AbstractTemperatureSensor() {};
};

#endif