#include <Arduino.h>
#include "./modules/pellet-burner/PelletBurner.h"

PelletBurner pelletBurner = PelletBurner();
byte testEEPROM;

void setup()
{
    pelletBurner.setup();
}

void loop()
{
    pelletBurner.run();
}