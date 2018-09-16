#ifndef GSM_H
#define GSM_H

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "../common/ExtendedHardwareUnit.h"

unsigned int RX, TX;
SoftwareSerial gsm(RX, TX);

<<<<<<< HEAD
class GSM : public ExtendedHardwareUnit{
    public:
        GSM();
        GSM(unsigned int RX, unsigned int TX);
        ~GSM();
        void setRXTX(unsigned int RX, unsigned int TX);
        void setup();
        void run();
        void sendSMS(String phone, String message);

    private:
        String sendATCommand(String value);
        String waitResponse();

=======
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
>>>>>>> c515d0676658c234434f0d965aa08052f11938b1
};

#endif