#ifndef AirTemperatureHumiditySensor_H
#define AirTemperatureHumiditySensor_H

#include "AbstractTemperatureSensor.h"
#include <Adafruit_AM2320.h>

class AirTemperatureHumiditySensor : public AbstractTemperatureSensor{
  public:
  Adafruit_AM2320 getSensor();
  void setup();

 private:
  Adafruit_AM2320 sensor = Adafruit_AM2320();
};

#endif
