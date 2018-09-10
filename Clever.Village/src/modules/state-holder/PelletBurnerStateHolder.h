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

        PelletBurnerState getState();
        void setState(PelletBurnerState newState);

        void setup();
    private:
        volatile PelletBurnerState state;

        byte convertStateToByte(PelletBurnerState stateToConvert);
        PelletBurnerState convertByteToState(byte convertedState);

        PelletBurnerState readStateFromEEPROM();
        void writeStateToEEPROM();
};

#endif