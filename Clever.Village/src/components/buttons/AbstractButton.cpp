#incude "AbstractButton.h"

    AbstractButton::AbstractButton() : HardwareUnit(){};
    AbstractButton::AbstractButton(unsigned int pin, int mode) : HardwareUnit(pin, mode){};
    ~AbstractButton(){};
    inline virtual void AbstractButton::onClick(){};
    inline virtual void AbstractButton::onHold(){};
    void AbstractButton::run() {}