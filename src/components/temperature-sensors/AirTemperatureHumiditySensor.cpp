#include "AirTemperatureHumiditySensor.h"

void AirTemperatureHumiditySensor::setup() {
  sensor.begin();
}

Adafruit_AM2320 AirTemperatureHumiditySensor::getSensor(){
  return sensor;
}