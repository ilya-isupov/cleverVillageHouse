#ifndef AirTemperatureHumiditySensor_H
#define AirTemperatureHumiditySensor_H

#include "AbstractTemperatureSensor.h"
#include  "lib/iarduino_AM2320.h"

class AirTemperatureHumiditySensor : public AbstractTemperatureSensor{
  public:
  void begin();
  int getTemperature();
  int getHumidity();

 private:
  iarduino_AM2320 sensor;
};

#endif
