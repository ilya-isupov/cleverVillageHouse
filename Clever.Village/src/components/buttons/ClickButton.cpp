#include "ClickButton.h"

    ClickButton::ClickButton() : AbstractButton() {};
    ClickButton::ClickButton(unsigned int pin, int mode) : AbstractButton(pin, mode){};
    ClickButton::~ClickButton();

    boolean ClickButton::ClickButtonOnce()
    {
		//реализация нажатия кнопки
    }

    boolean ClickButton::HoldButton()
    {
        // реализация удержания кнопки
    }