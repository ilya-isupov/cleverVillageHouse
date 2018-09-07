#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "../../components/buttons/PressButton.h"
#include "../../components/displays/Display16x2.h"
#include "../../components/lamps/DiodLamp.h"


class ControlPanel {
    PressButton<ControlPanel> forwardButton = PressButton<ControlPanel>(1, this);
    PressButton<ControlPanel> backwardButton = PressButton<ControlPanel>(1, this);
    PressButton<ControlPanel> okButton = PressButton<ControlPanel>(1, this);
    PressButton<ControlPanel> turnButton = PressButton<ControlPanel>(1, this);

    DiodLamp ignitionLamp = DiodLamp(1);
    DiodLamp burningLamp = DiodLamp(1);
    DiodLamp ignitionErrorLamp = DiodLamp(1);
    DiodLamp overheatLamp = DiodLamp(1);

    Display16x2 display = Display16x2();

    public:
        void setup();
        void run();

    private:
        static void onForwardClick(ControlPanel *context);
        static void onBackwardClick(ControlPanel *context);
        static void onOkClick(ControlPanel *context);
        static void onTurnClick(ControlPanel *context);

};

#endif