#ifndef OXYGENSENSOR_H
#define OXYGENSENSOR_H

#include "AbstractAirSensor.h"

class OxygenSensor : public AbstractAirSensor {
    public:
        OxygenSensor(uint8_t pin);
        ~OxygenSensor();
        void setup();
        void run();
        float getLambdaValue();
    private:
        static const float LAMBDA_TEMPLATE_VALUE = 104.0; // This is 0.5V in input pin
        static const unsigned long HEATING_TIME = 300000;
        float lambdaValue = 1.0;

        boolean workingMode = false;
        unsigned long startWork;        
        int currentValue;        
        float calculateLambda();
        void checkStartWorking();
        void setWorkingMode();
        boolean getWorkingMode();
};

#endif