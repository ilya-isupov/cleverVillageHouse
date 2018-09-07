#ifndef PELLETBURNER_H
#define PELLETBURNER_H

#include "Arduino.h"
#include "../../components/lamps/DiodLamp.h"
#include "../enums/PelletBurnerState.h"
#include "../state-holder/PelletBurnerStateHolder.h"

class PelletBurner {
    public:
        PelletBurner();
        ~PelletBurner();
        void setup();
        void run();

    private:
        PelletBurnerStateHolder pelletBurnerStateHolder = PelletBurnerStateHolder();
};

#endif