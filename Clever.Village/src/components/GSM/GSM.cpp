
#include "GSM.h"

void GSM::setup()
{
  gsm.begin(9600);
  String response = sendATCommand("AT+CMGF=1;&W");
}

void GSM::run()
{
  if (gsm.available())
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
  gsm.println(value);
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
  while (!gsm.available() && millis() < timeout)
  {
  };
  if (gsm.available())
  {
    resp = gsm.readString();
  }
  return resp;
}
void GSM::sendSMS(String phone, String message)
{
  sendATCommand("AT+CMGS=\"" + phone + "\"");
  sendATCommand(message + "\r\n" + (String)((char)26));
}