#ifndef Click_Button_cpp
#define Click_Button_cpp

#include "AbstractButton.cpp"

class ClickButton : AbstractButton
{

    unsigned int pin = 0;

    boolean butt_flag;
    boolean butt;
    boolean led_flag;
    unsigned long last_press;

  public:
    ClickButton(){};
    ClickButton(unsigned int pin, int mode) : AbstractButton(pin, mode){};
    ~ClickButton();

    boolean ClickButtonOnce()
    {
        boolean result;
        butt = !digitalRead(pin);
        if (butt == 1 && butt_flag == 0 && millis() - last_press > 50)
        {
            butt_flag = 1;
            // Serial.println("Button pressed");
            last_press = millis();
            result = true;
        }
        if (butt == 0 && butt_flag == 1)
        {
            butt_flag = 0;
            result = false;
        }
        return result;
    }

    boolean HoldButton()
    {
        boolean result;
        if (butt == 1 && butt_flag == 1 && millis() - last_press > 200)
        {
            //Serial.println("Button hold");
            result = true;
        }
        if (butt == 0 && butt_flag == 1)
        {
            butt_flag = 0;
            result = false;
        }
        return result;
    }
};

#endif