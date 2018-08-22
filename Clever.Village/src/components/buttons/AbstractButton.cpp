#include "AbstractButton.h"

    AbstractButton::AbstractButton() : HardwareUnit(){};
    AbstractButton::AbstractButton(unsigned int pin, int mode) : HardwareUnit(pin, mode){};
    ~AbstractButton(){};
    inline void AbstractButton::onClick(){};
    inline void AbstractButton::onHold(){};
    void AbstractButton::run() {}