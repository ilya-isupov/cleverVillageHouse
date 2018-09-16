#ifndef GSM_H
#define GSM_H


#include "SoftwareSerial.h"
#include "../common/ExtendedHardwareUnit.h"

unsigned int RX,TX;
SoftwareSerial gsm(RX, TX);

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

};

#endif