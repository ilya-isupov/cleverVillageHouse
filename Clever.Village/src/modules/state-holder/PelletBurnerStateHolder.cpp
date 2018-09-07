#include "PelletBurnerStateHolder.h"

PelletBurnerStateHolder::PelletBurnerStateHolder() {}
PelletBurnerStateHolder::~PelletBurnerStateHolder() {}

PelletBurnerState PelletBurnerStateHolder::readStateFromEEPROM() {
    return convertByteToState(EepromController::read(EEPROM_PelletBurnerStateAddress));
}

void PelletBurnerStateHolder::writeStateToEEPROM() {
    EepromController::write(EEPROM_PelletBurnerStateAddress, convertStateToByte(state));
}

PelletBurnerState PelletBurnerStateHolder::getState() {
    return state;
}

void PelletBurnerStateHolder::setState(PelletBurnerState newState) {
    state = newState;
}

void PelletBurnerStateHolder::setup() {
    state = readStateFromEEPROM();
    if(!state) {
        state = LEARNING;
        //start learn
    }
}

PelletBurnerState PelletBurnerStateHolder::convertByteToState(byte convertedState) {
    switch(convertedState) {
        case 0:
            return IDLE;
        case 1:
            return IGNITION;
        case 2:
            return IGNITION_ERROR;
        case 3:
            return BURNING_HARD;
        case 4:
            return BURNING_LIGHT;
        case 5:
            return OVERHEAT;
        case 6:
            return LEARNING;
    }
}

byte PelletBurnerStateHolder::convertStateToByte(PelletBurnerState stateToConvert) {
    switch(stateToConvert) {
        case IDLE: 
            return 0;
        case IGNITION:
            return 1;
        case IGNITION_ERROR:
            return 2;
        case BURNING_HARD:
            return 3;
        case BURNING_LIGHT:
            return 4;
        case OVERHEAT:
            return 5;
        case LEARNING:
            return 6;
        
    }
}