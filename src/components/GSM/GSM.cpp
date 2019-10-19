
#include "GSM.h"

GSM::GSM(uint8_t Rx, uint8_t Tx) {
  this->setRxTx(Rx, Tx);
  this->serialInterface = new SoftwareSerial(Rx, Tx);
}

void GSM::setRxTx(uint8_t Rx, uint8_t Tx) {
  this->Rx = Rx;
  this->Tx = Tx;
}

void GSM::setup()
{
  this->serialInterface->begin(9600);
  String response = sendATCommand("AT+CMGF=1;&W");
}

bool GSM::onResponse() {
  bool val = false;
  if (this->serialInterface->available()) {
    val = true;
  }
  return val;
}

void GSM::run()
{
  if (this->serialInterface->available())
  {
    String response = waitResponse();
    response.trim();

    if (response.startsWith("+CIEV:"))
    {

      int index = response.lastIndexOf("\"");
      String result = response.substring(index + 1, response.length());
      result.trim();
      // if (result.equals("testred")) digitalWrite(8,!digitalRead(8)); Делаем что-то в зависимости от сообщения

      sendATCommand("AT+CMGD=4"); // Удалить все сообщения
    }
  }
}
String GSM::sendATCommand(String value)
{
  String resp = "";
  this->serialInterface->println(value);
  resp = waitResponse();
  if (resp.startsWith(value))
  {
    resp = resp.substring(resp.indexOf("\r", value.length()) + 2);
  }

  return resp;
}

String GSM::waitResponse()
{
  String resp = "";
  long timeout = millis() + 10000;
  while (!this->serialInterface->available() && millis() < timeout)
  {
  };
  if (this->serialInterface->available())
  {
    resp = this->serialInterface->readString();
  }
  return resp;
}
void GSM::sendSMS(String phone, String message)
{
  sendATCommand("AT+CMGS=\"" + phone + "\"");
  sendATCommand(message + "\r\n" + (String)((char)26));
}