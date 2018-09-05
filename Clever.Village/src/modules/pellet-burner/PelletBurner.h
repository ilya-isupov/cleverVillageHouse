#ifndef PELLETBURNER_H
#define PELLETBURNER_H

#include "../../components/lamps/DiodLamp.h"

class PelletBurner {
    public:
        PelletBurner();
        ~PelletBurner();
        void setup();
        void run();
};

#endif