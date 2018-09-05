#include <Arduino.h>
#include "./modules/pellet-burner/PelletBurner.h"

PelletBurner pelletBurner = PelletBurner();

void setup() {
     pelletBurner.setup();
}

void loop() {
    pelletBurner.run();
}