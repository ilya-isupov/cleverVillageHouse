#include "AirTemperatureHumiditySensor.h"

void setup() {
  sensor.begin();
}

int AirTemperatureHumiditySensor::getTemperature() {
  return sensor.readTemperature;
}
int AirTemperatureHumiditySensor::getHumidity() {
  return sensor.readHumidity;
}