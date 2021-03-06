#ifndef Abstract_Air_Sensor_cpp
#define Abstract_Air_Sensor_cpp

#include "../common/SimpleHardwareUnit.h"

class AbstractAirSensor : public SimpleHardwareUnit {
    public:
        AbstractAirSensor(uint8_t pin);
        ~AbstractAirSensor();
        void setup();
        void run();
};

#endif