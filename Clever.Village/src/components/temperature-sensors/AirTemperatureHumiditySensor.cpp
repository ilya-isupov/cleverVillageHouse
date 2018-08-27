#include "AirTemperatureHumiditySensor.h"

AirTemperatureHumiditySensor::AirTemperatureHumiditySensor(uint8_t type, uint8_t count) 
 {
   _type = type;	 
   firstreading = true;
   lastreadtime = 0;
 }

int AirTemperatureHumiditySensor::readTemperature(int PINS) 
{
   pin = PINS;	
   bit = digitalPinToBitMask(pin);
   port = digitalPinToPort(pin);
   maxcycles = microsecondsToClockCycles(1000);  
 
  int f = NAN;
  
  if(read()) 
   {
    switch (_type) 
    {
    case TemperatureSensor11:
      f = data[2];
      break;
      
    case TemperatureSensor22:
    case TemperatureSensor21:
      f = data[2] & 0x7F;
      f *= 256;
      f += data[3];
      f /= 10;
      if(data[2] & 0x80) 
       {
        f *= -1;
       }
      break;
     }
   }
   
  return f;
}

int AirTemperatureHumiditySensor::readHumidity(int PONS) 
 {
   pin = PONS;	
   bit = digitalPinToBitMask(pin);
   port = digitalPinToPort(pin);
   maxcycles = microsecondsToClockCycles(1000); 
   	 
   int f = NAN;
   if(read()) 
    {
     switch (_type) 
      {
       case TemperatureSensor11:
        f = data[0];
        break;
        
       case TemperatureSensor22:
       case TemperatureSensor21:
        f = data[0];
        f *= 256;
        f += data[1];
        f /= 10;
        break;
    }
  }
    
   return f;
 }

boolean AirTemperatureHumiditySensor::read(void) 
{
  uint32_t currenttime = millis();
  if(currenttime < lastreadtime) 
    {
      lastreadtime = 0;
    }
    
  if(!firstreading && ((currenttime - lastreadtime) < 2000)) 
    {
      return lastresult; 
    }
    
  firstreading = false;
  lastreadtime = millis();

  data[0] = data[1] = data[2] = data[3] = data[4] = 0;

  digitalWrite(pin, HIGH);
  delay(50);//////////////////////// Изначально это значение было - 250. Если что-то будет работать "криво",
  ////////////////////////////////// попробуйте увеличивать значение с 50-ти до 60 и т.д.

  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delay(20); 

  uint32_t cycles[80];
  {
    InterruptLock lock;
    digitalWrite(pin, HIGH);
    delayMicroseconds(40);
    pinMode(pin, INPUT);
    delayMicroseconds(10);  

    if(expectPulse(LOW) == 0) 
     {
      lastresult = false;
      return lastresult;
     }
     
    if(expectPulse(HIGH) == 0) 
     {
      lastresult = false;
      return lastresult;
     }


    for(int i=0; i<80; i+=2) 
     {
      cycles[i]   = expectPulse(LOW);
      cycles[i+1] = expectPulse(HIGH);
     }
  } 

  for(int i=0; i<40; ++i) 
   {
     uint32_t lowCycles  = cycles[2*i];
     uint32_t highCycles = cycles[2*i+1];
     if((lowCycles == 0) || (highCycles == 0)) 
      {
        lastresult = false;
        return lastresult;
      }
    data[i/8] <<= 1;

    if(highCycles > lowCycles) 
     {
       data[i/8] |= 1;
     }
   }


  if(data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) 
   {
     lastresult = true;
     return lastresult;
   }
   
  else 
   {
     lastresult = false;
     return lastresult;
   }
}

uint32_t AirTemperatureHumiditySensor::expectPulse(bool level) 
 {
    uint32_t count = 0;
    uint8_t portState = level ? bit : 0;
    while((*portInputRegister(port) & bit) == portState) 
     {
      if(count++ >= maxcycles) 
       {
        return 0;
       }
     }

   return count;
}
