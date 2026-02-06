#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include <Arduino.h>
#include "Config.h"

class InputController {
private:
    bool joyXCentered;
    bool joyYCentered;
    uint8_t lastJoySWState;

    const uint16_t xMinThreshold = 495;
    const uint16_t xMaxThreshold = 528;
    const uint16_t yMinThreshold = 493;
    const uint16_t yMaxThreshold = 523;

    int lastBtnState[4];
    unsigned long lastDebounceTime[4];

public:
    InputController();

    void init();
    bool isButtonDown(int index);
    uint16_t readX();
    uint16_t readY();
    void resetCenters();
    bool movedLeft();
    bool movedRight();
    bool movedUp();
    bool movedDown();
    bool isJoystickUp();
    bool isJoystickDown();
    bool isJoystickRight();
    bool isJoystickLeft();
    bool isPressed();
    int getPressedButtonIndex();
};

#endif
