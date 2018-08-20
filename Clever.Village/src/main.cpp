#include <Arduino.h>
#include "./modules/pellet-burner/PelletBurner.cpp"

PelletBurner *pelletBurner = new PelletBurner;

void setup() {
     pelletBurner->setup();
}

void loop() {
    pelletBurner->run();
}