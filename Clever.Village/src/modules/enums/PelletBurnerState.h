#ifndef PELLETBURDERSTATE_H
#define PELLETBURDERSTATE_H

enum PelletBurnerState {
    IDLE,
    IGNITION,
    IGNITION_ERROR,
    BURNING_HARD,
    BURNING_LIGHT,
    OVERHEAT,
    LEARNING
};

#endif