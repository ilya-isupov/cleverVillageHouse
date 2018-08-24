#ifndef Abstract_Temperature_Sensor_cpp
#define Abstract_Temperature_Sensor_cpp

#include "../common/HardwareUnit.h"

class AbstractTemperatureSensor : public HardwareUnit {
    public:
        AbstractTemperatureSensor() : HardwareUnit() {};
        AbstractTemperatureSensor(unsigned int pin, int mode) : HardwareUnit(pin, mode) {};
        ~AbstractTemperatureSensor() {};
        void setup();
        void run();

};

#endif