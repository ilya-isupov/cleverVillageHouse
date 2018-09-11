#include "ControlPanel.h"

ControlPanel::ControlPanel() {}
ControlPanel::~ControlPanel() {}

void ControlPanel::setup()
{
    // forwardButton.attachClick(onForwardClick);
    // forwardButton.attachLongPressStart(onForwardLongPressStart);
    // forwardButton.attachLongPressStop(onForwardLongPressStop);

    // backwardButton.attachClick(onBackwardClick);
    // backwardButton.attachLongPressStart(onBackwardLongPressStart);
    // backwardButton.attachLongPressStop(onBackwardLongPressStop);

    // okButton.attachClick(onOkClick);
    // turnButton.attachClick(onTurnClick);
}

void ControlPanel::run()
{
    if (checkNeseccityShowSettings())
    {
        openSettings();
    }
}

void openSettings()
{
    //open settings menu
}

void ControlPanel::onForwardClick(ControlPanel *controlPanel)
{
}

void ControlPanel::onBackwardClick(ControlPanel *controlPanel)
{
}

void ControlPanel::onOkClick(ControlPanel *controlPanel)
{
}

void ControlPanel::onTurnClick(ControlPanel *controlPanel)
{
}

void ControlPanel::onForwardLongPressStart(ControlPanel *controlPanel)
{
    controlPanel->isForwardButtonPressingNow = true;
}

void ControlPanel::onForwardLongPressStop(ControlPanel *controlPanel)
{
    controlPanel->isForwardButtonPressingNow = false;
}

void ControlPanel::onBackwardLongPressStart(ControlPanel *controlPanel)
{
    controlPanel->isBackwardButtonPressingNow = true;
}

void ControlPanel::onBackwardLongPressStop(ControlPanel *controlPanel)
{
    controlPanel->isBackwardButtonPressingNow = false;
}

boolean ControlPanel::checkNeseccityShowSettings()
{
    return isForwardButtonPressingNow && isBackwardButtonPressingNow;
}
