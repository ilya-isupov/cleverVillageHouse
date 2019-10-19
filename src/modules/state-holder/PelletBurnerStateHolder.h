#ifndef PELLETBURNERSTATEHOLDER_H
#define PELLETBURNERSTATEHOLDER_H

#include "Arduino.h"
#include "../enums/PelletBurnerState.h"
#include "../constants/eeprom-constants/AddressList.h"
#include "../../components/eeprom-controller/EepromController.h"

class PelletBurnerStateHolder {
    public:
        PelletBurnerStateHolder();
        ~PelletBurnerStateHolder();

        int getState();
        void setState(int newState);

        void setup();
    private:
        volatile int state;

        int readStateFromEEPROM();
        void writeStateToEEPROM();
};

#endif