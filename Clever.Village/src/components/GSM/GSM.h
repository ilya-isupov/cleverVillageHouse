#ifndef GSM_H
#define GSM_H

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "../common/ExtendedHardwareUnit.h"

unsigned int RX, TX;
SoftwareSerial gsm(RX, TX);

class GSM : public ExtendedHardwareUnit
{
  public:
    GSM(uint8_t RX, uint8_t TX);
    ~GSM();
    void setup();
    void run();
    void sendSMS(String phone, String message);
    String sendATCommand(String value);
    String waitResponse();
};

#endif