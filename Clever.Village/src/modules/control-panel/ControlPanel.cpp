#include "ControlPanel.h"

void ControlPanel::setup() {
    forwardButton.attachClick(onForwardClick);
    forwardButton.attachLongPressStart(onForwardLongPressStart);
    forwardButton.attachLongPressStop(onForwardLongPressStop);


    backwardButton.attachClick(onBackwardClick);
    backwardButton.attachLongPressStart(onBackwardLongPressStart);
    backwardButton.attachLongPressStop(onBackwardLongPressStop);

    okButton.attachClick(onOkClick);
    turnButton.attachClick(onTurnClick);
}

void ControlPanel::run() {
    if(checkNeseccityShowSettings()) {
        openSettings();
    }
}

void openSettings() {
    //open settings menu
}

void ControlPanel::onForwardClick(ControlPanel *context) {
}

void ControlPanel::onBackwardClick(ControlPanel *context) {
}

void ControlPanel::onOkClick(ControlPanel *context) {
}

void ControlPanel::onTurnClick(ControlPanel *context) {
}

void ControlPanel::onForwardLongPressStart(ControlPanel *context) {
    context->isForwardButtonPressingNow = true;
}

void ControlPanel::onForwardLongPressStop(ControlPanel *context) {
    context->isForwardButtonPressingNow = false;
}

void ControlPanel::onBackwardLongPressStart(ControlPanel *context) {
    context->isBackwardButtonPressingNow = true;
}

void ControlPanel::onBackwardLongPressStop(ControlPanel *context) {
    context->isBackwardButtonPressingNow = false;
}

boolean ControlPanel::checkNeseccityShowSettings() {
    return isForwardButtonPressingNow && isBackwardButtonPressingNow;
}

