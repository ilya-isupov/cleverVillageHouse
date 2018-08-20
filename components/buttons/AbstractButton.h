#ifndef ABSTRACT_BUTTON_H
#define ABSTRACT_BUTTON_H
#endif

class AbstractButton {
    public:
        AbstractButton();
        ~AbstractButton();
        void setPin(byte pin, int mode);
        
    
    protected:
        byte hardwarePinNumber;
        int hardwarePinMode;
}