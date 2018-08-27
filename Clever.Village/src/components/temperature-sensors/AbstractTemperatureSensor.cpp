#include "AbstractTemperatureSensor.h"

        AbstractTemperatureSensor::AbstractTemperatureSensor() : SimpleHardwareUnit() {};
        AbstractTemperatureSensor::AbstractTemperatureSensor(unsigned int pin, int mode) : SimpleHardwareUnit(pin, mode) {
            
        };
        AbstractTemperatureSensor::~AbstractTemperatureSensor() {};
        void AbstractTemperatureSensor::setup(){};
        void AbstractTemperatureSensor::run(){};