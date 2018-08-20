#include "../common/HardwareUnit.cpp"

class AbstractTemperatureSensor : HardwareUnit {
    public:
        AbstractTemperatureSensor() {};
        AbstractTemperatureSensor(unsigned int pin, int mode) {
            HardwareUnit(pin, mode);
        }
        ~AbstractTemperatureSensor() {};
};