#ifndef PELLETBURDERSTATE_H
#define PELLETBURDERSTATE_H

class PelletBurnerState
{
  public:
    static const int8_t IDLE = 0x1;
    static const int8_t IGNITION = 0x2;
    static const int8_t IGNITION_ERROR = 0x3;
    static const int8_t BURNING_HARD = 0x4;
    static const int8_t BURNING_LIGHT = 0x5;
    static const int8_t OVERHEAT = 0x6;
    static const int8_t LEARNING = 0x7;
};

#endif