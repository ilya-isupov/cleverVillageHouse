#include "ClickButton.h"

    ClickButton::ClickButton() : AbstractButton() {};
    ClickButton::ClickButton(unsigned int pint, int modet) : AbstractButton(pin, mode){
		pin = pint;
		mode = modet;
	};
    ClickButton::~ClickButton() {};

    boolean ClickButton::ClickButtonOnce()
    {
		//реализация нажатия кнопки
    }

    boolean ClickButton::HoldButton()
    {
        // реализация удержания кнопки
    }