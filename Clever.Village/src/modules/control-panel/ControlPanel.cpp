#include "ControlPanel.h"

void ControlPanel::setup() {
    forwardButton.attachClick(onForwardClick);
    backwardButton.attachClick(onBackwardClick);
    okButton.attachClick(onOkClick);
    turnButton.attachClick(onTurnClick);
}