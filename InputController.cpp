#include "InputController.h"

InputController::InputController()
    : joyXCentered(true),
      joyYCentered(true),
      lastJoySWState(HIGH)
{
    for (int i = 0; i < 4; i++) {
        lastBtnState[i] = HIGH;
        lastDebounceTime[i] = 0;
    }
}

void InputController::init() {
    pinMode(joySW, INPUT_PULLUP);
    for (int i = 0; i < 4; i++) {
        pinMode(btnPins[i], INPUT_PULLUP);
    }
}

uint16_t InputController::readX() {
    return analogRead(joyX);
}

uint16_t InputController::readY() {
    return analogRead(joyY);
}

void InputController::resetCenters() {
    uint16_t xVal = readX();
    uint16_t yVal = readY();

    joyXCentered = (xVal >= xMinThreshold && xVal <= xMaxThreshold);
    joyYCentered = (yVal >= yMinThreshold && yVal <= yMaxThreshold);
}

bool InputController::movedLeft() {
    uint16_t x = readX();
    if (joyXCentered && x < xMinThreshold) {
        joyXCentered = false;
        return true;
    }
    if (x >= xMinThreshold && x <= xMaxThreshold) {
        joyXCentered = true;
    }
    return false;
}

bool InputController::movedRight() {
    uint16_t x = readX();
    if (joyXCentered && x > xMaxThreshold) {
        joyXCentered = false;
        return true;
    }
    if (x >= xMinThreshold && x <= xMaxThreshold) {
        joyXCentered = true;
    }
    return false;
}

bool InputController::movedUp() {
    uint16_t y = readY();
    if (joyYCentered && y < yMinThreshold) {
        joyYCentered = false;
        return true;
    }
    if (y >= yMinThreshold && y <= yMaxThreshold) {
        joyYCentered = true;
    }
    return false;
}

bool InputController::movedDown() {
    uint16_t y = readY();
    if (joyYCentered && y > yMaxThreshold) {
        joyYCentered = false;
        return true;
    }
    if (y >= yMinThreshold && y <= yMaxThreshold) {
        joyYCentered = true;
    }
    return false;
}

bool InputController::isJoystickUp() {
    return readY() < yMinThreshold;
}

bool InputController::isJoystickDown() {
    return readY() > yMaxThreshold;
}

bool InputController::isJoystickRight() {
    return readX() > xMaxThreshold;
}

bool InputController::isJoystickLeft() {
    return readX() < xMinThreshold;
}

bool InputController::isButtonDown(int index) {
    return digitalRead(btnPins[index]) == HIGH;
}

bool InputController::isPressed() {
    int sw = digitalRead(joySW);
    bool pressed = (sw == LOW && lastJoySWState == HIGH);
    lastJoySWState = sw;
    return pressed;
}

int InputController::getPressedButtonIndex() {
    for (int i = 0; i < 4; i++) {
        int reading = digitalRead(btnPins[i]);

        if (reading != lastBtnState[i]) {
            lastDebounceTime[i] = millis();
            lastBtnState[i] = reading;
        }

        if ((millis() - lastDebounceTime[i]) > debounceDelay) {
            if (reading == LOW) {
                return i;
            }
        }
    }
    return -1;
}
