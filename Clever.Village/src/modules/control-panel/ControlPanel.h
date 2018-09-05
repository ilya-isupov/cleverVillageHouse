#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "../../components/buttons/ClickButton.h"
#include "../../components/displays/Display16x2.h"
#include "../../components/lamps/DiodLamp.h"


class ControlPanel {
    ClickButton forwardButton = ClickButton(1);
    ClickButton backwardButton = ClickButton(1);
    ClickButton okButton = ClickButton(1);
    ClickButton turnButton = ClickButton(1);

    DiodLamp ignitionLamp = DiodLamp(1);
    DiodLamp burningLamp = DiodLamp(1);
    DiodLamp ignitionErrorLamp = DiodLamp(1);
    DiodLamp overheatLamp = DiodLamp(1);

    Display16x2 display = Display16x2();

    public:
        void setup();
        void run();

};

#endif