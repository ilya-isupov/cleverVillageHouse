#include "AirTemperatureHumiditySensor.h"

void AirTemperatureHumiditySensor::begin() {
  sensor.begin();
}

int AirTemperatureHumiditySensor::getTemperature() {
  return sensor.tem;
}
int AirTemperatureHumiditySensor::getHumidity() {
  return sensor.hum;
}