#include "AbstractTemperatureSensor.h"

        AbstractTemperatureSensor::AbstractTemperatureSensor(unsigned int pin) : SimpleHardwareUnit(pin, INPUT_PULLUP){};
        AbstractTemperatureSensor::~AbstractTemperatureSensor() {};
        void AbstractTemperatureSensor::setup(){};
        void AbstractTemperatureSensor::run(){};