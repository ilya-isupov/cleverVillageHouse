#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "../../components/buttons/PressButton.h"
#include "../../components/displays/Display16x2.h"
#include "../../components/lamps/DiodLamp.h"
#include "../enums/ControlPanelState.h"

class ControlPanel
{
    byte testPin = 1;
    //PressButton<ControlPanel> forwardButton = PressButton<ControlPanel>(testPin, this);
    // PressButton<ControlPanel> backwardButton = PressButton<ControlPanel>(1, this);
    // PressButton<ControlPanel> okButton = PressButton<ControlPanel>(1, this);
    // PressButton<ControlPanel> turnButton = PressButton<ControlPanel>(1, this);

    // DiodLamp ignitionLamp = DiodLamp(1);
    // DiodLamp burningLamp = DiodLamp(1);
    // DiodLamp ignitionErrorLamp = DiodLamp(1);
    // DiodLamp overheatLamp = DiodLamp(1);

    // Display16x2 display = Display16x2();

  public:
    ControlPanel();
    ~ControlPanel();
    void setup();
    void run();

  private:
    static void onForwardClick(ControlPanel *controlPanel);
    static void onForwardLongPressStart(ControlPanel *controlPanel);
    static void onForwardLongPressStop(ControlPanel *controlPanel);
    volatile boolean isForwardButtonPressingNow = false;

    static void onBackwardClick(ControlPanel *controlPanel);
    static void onBackwardLongPressStart(ControlPanel *controlPanel);
    static void onBackwardLongPressStop(ControlPanel *controlPanel);
    volatile boolean isBackwardButtonPressingNow = false;

    static void onOkClick(ControlPanel *controlPanel);
    static void onTurnClick(ControlPanel *controlPanel);

    boolean checkNeseccityShowSettings();
    void openSettings();

    volatile ControlPanelState state = WORK;
};

#endif