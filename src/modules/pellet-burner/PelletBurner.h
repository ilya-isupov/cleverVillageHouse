#ifndef PELLETBURNER_H
#define PELLETBURNER_H

#include "Arduino.h"
#include "../../components/lamps/DiodLamp.h"
#include "../enums/PelletBurnerState.h"
#include "../state-holder/PelletBurnerStateHolder.h"
#include "../control-panel/ControlPanel.h"

class PelletBurner {
    public:
        PelletBurner();
        ~PelletBurner();
        void setup();
        void run();

    private:
        ControlPanel controlPanel;
        PelletBurnerStateHolder pelletBurnerStateHolder;
};

#endif