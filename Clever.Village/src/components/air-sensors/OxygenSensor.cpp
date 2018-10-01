#include "OxygenSensor.h"

OxygenSensor::OxygenSensor(uint8_t pin) : AbstractAirSensor(pin) {};
OxygenSensor::~OxygenSensor(){};
void OxygenSensor::run() {
    AbstractAirSensor::run();
    if(getWorkingMode()) {
        calculateLambda();
    }    
}
void OxygenSensor::setup() {
    AbstractAirSensor::setup();
    startWork = millis();
}
float OxygenSensor::getLambdaValue() {
    return lambdaValue;
}
float OxygenSensor::calculateLambda() {
    lambdaValue = currentValue / LAMBDA_TEMPLATE_VALUE; 
}
void OxygenSensor::checkStartWorking() {
    unsigned long currentTime = millis();
    if(currentTime > HEATING_TIME) {
        setWorkingMode(true);
    }    
}
void OxygenSensor::setWorkingMode(boolean mode) {
    workingMode = mode;
}
boolean OxygenSensor::getWorkingMode() {
    return workingMode;
}
