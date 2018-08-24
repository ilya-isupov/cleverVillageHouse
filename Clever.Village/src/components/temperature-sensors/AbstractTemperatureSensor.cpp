#include "AbstractTemperatureSensor.h"

        AbstractTemperatureSensor::AbstractTemperatureSensor() : HardwareUnit() {};
        AbstractTemperatureSensor::AbstractTemperatureSensor(unsigned int pin, int mode) : HardwareUnit(pin, mode) {
            
        };
        AbstractTemperatureSensor::~AbstractTemperatureSensor() {};
        void AbstractTemperatureSensor::setup(){};
        void AbstractTemperatureSensor::run(){};