#ifndef AirTemperatureHumiditySensor_H
#define AirTemperatureHumiditySensor_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "AbstractTemperatureSensor.h"


#define TemperatureSensor11 11
#define TemperatureSensor22 22
#define TemperatureSensor21 21

class AirTemperatureHumiditySensor : public AbstractTemperatureSensor{
  public:
   AirTemperatureHumiditySensor(uint8_t type, uint8_t count=6);
   int readTemperature(int PINS);
   int readHumidity(int PONS);
   boolean read(void);

 private:
  uint8_t data[6];
  uint8_t pin, _type, bit, port;
  uint32_t lastreadtime, maxcycles;
  bool firstreading;
  bool lastresult;

  uint32_t expectPulse(bool level);

};

#endif
