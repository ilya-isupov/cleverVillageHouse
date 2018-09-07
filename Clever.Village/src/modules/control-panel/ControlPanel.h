#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "../../components/buttons/PressButton.h"
#include "../../components/displays/Display16x2.h"
#include "../../components/lamps/DiodLamp.h"


class ControlPanel {
    PressButton forwardButton = PressButton(1);
    PressButton backwardButton = PressButton(1);
    PressButton okButton = PressButton(1);
    PressButton turnButton = PressButton(1);

    DiodLamp ignitionLamp = DiodLamp(1);
    DiodLamp burningLamp = DiodLamp(1);
    DiodLamp ignitionErrorLamp = DiodLamp(1);
    DiodLamp overheatLamp = DiodLamp(1);

    Display16x2 display = Display16x2();

    public:
        void setup();
        void run();

    private:
        static void onForwardClick();
        static void onBackwardClick();
        static void onOkClick();
        static void onTurnClick();

};

#endif