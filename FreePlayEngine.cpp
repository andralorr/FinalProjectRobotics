#include "FreePlayEngine.h"

FreePlayEngine::FreePlayEngine(InputController* in, LcdRenderer* lcdR): input(in), lcd(lcdR) {}

void FreePlayEngine::init() {
    exitRequested = false;
    noTone(buzzerPin);
    loopCount = 0;
    isRecording = false;
    isSustainActive = false;
    displayInfo();
}

void FreePlayEngine::update() {
    int activeNote = -1;
    bool anyPressed = false;
    unsigned long now = millis();

    detectNoteButtons(activeNote, anyPressed);
    handleJoystickClick(anyPressed, activeNote);
    updateSound(activeNote, anyPressed);
    handleOctaveAndWaveform(now);
}

void FreePlayEngine::detectNoteButtons(int& activeNote, bool& anyPressed) {
    for (int i = 0; i < 4; i++) {
        bool isDown = input->isButtonDown(i);

        if (isDown) {
            digitalWrite(ledPins[i], HIGH);
            activeNote = i;
            anyPressed = true;

            if (isSustainActive && i != sustainedNoteIndex) {
                isSustainActive = false;
            }

            if (isRecording && !lastButtonState[i] && loopCount < max_loop) {
                loopNotes[loopCount] = i;
                loopOctaves[loopCount] = currentOctave;
                loopWaveforms[loopCount] = currentWaveform;
                loopCount++;
            }
        } else {
            digitalWrite(ledPins[i], LOW);
        }

        lastButtonState[i] = isDown;
    }
}

void FreePlayEngine::handleJoystickClick(bool anyPressed, int activeNote) {
    if (!input->isPressed()) return;

    unsigned long now = millis();

    if (now - lastClickTime < 400) {
        noTone(buzzerPin);
        loopCount = 0;
        isRecording = false;
        isSustainActive = false;
        exitRequested = true;
    }

    if (anyPressed) {
        isSustainActive = !isSustainActive;
        sustainedNoteIndex = activeNote;
        sustainedOctave = currentOctave;
        sustainedWaveform = currentWaveform;
    } else {
        if (!isRecording && loopCount == 0) {
            isRecording = true;
            loopCount = 0;
        } else if (isRecording) {
            isRecording = false;
            currentPlayIndex = 0;
            lastLoopMillis = millis();
        } else if (loopCount > 0) {
            loopCount = 0;
            currentPlayIndex = 0;
            lastLoopMillis = 0;
        }
    }

    lastClickTime = now;
    displayInfo();
}

void FreePlayEngine::updateSound(int activeNote, bool anyPressed) {
    unsigned long now = millis();

    if (anyPressed) {
        playNote(activeNote, currentOctave, currentWaveform);
    }
    else if (!isRecording && loopCount > 0 && !anyPressed) {
        if (now - lastLoopMillis > 400) {
            currentPlayIndex = (currentPlayIndex + 1) % loopCount;
            lastLoopMillis = now;
        }
        playNote(loopNotes[currentPlayIndex], loopOctaves[currentPlayIndex], loopWaveforms[currentPlayIndex]);
    }
    else if (isSustainActive) {
        playNote(sustainedNoteIndex, sustainedOctave, sustainedWaveform);
    }
    else {
        noTone(buzzerPin);
    }
}


void FreePlayEngine::handleOctaveAndWaveform(unsigned long now) {
    if (now - lastJoystickMove < 300) return;

    if (input->isJoystickLeft() && currentOctave > 0) {
        currentOctave--;
    } else if (input->isJoystickRight() && currentOctave < 2) {
        currentOctave++;
    }

    if (input->isJoystickUp()) {
        currentWaveform = (currentWaveform + 1) % 3;
    }

    displayInfo();
    lastJoystickMove = now;
}


void FreePlayEngine::playNote(int noteIndex, int octave, int waveform) {
    int frequency = note_frequencies[noteIndex][octave];
    unsigned long now = millis();

    switch(waveform) {
        case 0: // Normal
            tone(buzzerPin, frequency);
            break;
        case 1: // Vibrato
            if (now - lastEffectUpdate > 30) {
                vibratoOffset = (vibratoOffset == 10) ? -10 : 10;
                lastEffectUpdate = now;
            }
            tone(buzzerPin, frequency + vibratoOffset);
            break;
        case 2: // Staccato
            if (now - lastEffectUpdate > 100) {
                staccatoOn = !staccatoOn;
                lastEffectUpdate = now;
            }
            if (staccatoOn) tone(buzzerPin, frequency);
            else noTone(buzzerPin);
            break;
    }
}

void FreePlayEngine::displayInfo() {
    lcd->showFreePlayDetail(currentOctave, currentWaveform, isSustainActive, isRecording, loopCount);
}


bool FreePlayEngine::wantsExit() const {
    return exitRequested;
}