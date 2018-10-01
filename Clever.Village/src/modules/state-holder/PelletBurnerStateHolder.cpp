#include "PelletBurnerStateHolder.h"

PelletBurnerStateHolder::PelletBurnerStateHolder() {}
PelletBurnerStateHolder::~PelletBurnerStateHolder() {}

int PelletBurnerStateHolder::readStateFromEEPROM() {
    return EepromController::read(EEPROM_PelletBurnerStateAddress);
}

void PelletBurnerStateHolder::writeStateToEEPROM() {
    EepromController::write(EEPROM_PelletBurnerStateAddress, state);
}

int PelletBurnerStateHolder::getState() {
    return state;
}

void PelletBurnerStateHolder::setState(int newState) {
    state = newState;
}

void PelletBurnerStateHolder::setup() {
    state = readStateFromEEPROM();
    if(state == EepromController::EMPTY_VALUE) {
        setState(PelletBurnerState::LEARNING);
        writeStateToEEPROM();
    }
}