#include "ControlPanel.h"

void ControlPanel::setup() {
    forwardButton.attachClick(onForwardClick);
    backwardButton.attachClick(onBackwardClick);
    okButton.attachClick(onOkClick);
    turnButton.attachClick(onTurnClick);
}

void ControlPanel::onForwardClick(ControlPanel *context) {
}

void ControlPanel::onBackwardClick(ControlPanel *context) {
}

void ControlPanel::onOkClick(ControlPanel *context) {
}

void ControlPanel::onTurnClick(ControlPanel *context) {
}