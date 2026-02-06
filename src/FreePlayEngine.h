#ifndef FREEPLAYENGINE_H
#define FREEPLAYENGINE_H

#include "InputController.h"
#include "LcdRenderer.h"
#include "Config.h"

class FreePlayEngine {

private:
    InputController* input;
    LcdRenderer* lcd;

    uint8_t currentOctave = 1;
    uint8_t currentWaveform = 0;

    bool isSustainActive = false;
    bool isRecording = false;

    int sustainedNoteIndex = -1;
    int sustainedOctave = -1;
    int sustainedWaveform = -1;

    static const int max_loop = 40;
    int loopNotes[max_loop];
    int loopOctaves[max_loop];
    int loopWaveforms[max_loop];
    int loopCount = 0;
    int currentPlayIndex = 0;

    bool lastButtonState[4] = {false};
    unsigned long lastClickTime = 0;
    unsigned long lastLoopMillis = 0;
    unsigned long lastJoystickMove = 0;
    unsigned long lastEffectUpdate = 0;
    int vibratoOffset = 0;
    bool staccatoOn = true;

    bool exitRequested = false;

    void detectNoteButtons(int& activeNote, bool& anyPressed);
    void handleJoystickClick(bool anyPressed, int activeNote);
    void updateSound(int activeNote, bool anyPressed);
    void handleOctaveAndWaveform(unsigned long now);
    void playNote(int noteIndex, int octave, int waveform);
    void displayInfo();

public:
    FreePlayEngine(InputController* in, LcdRenderer* lcd);
    void init();
    void update();
    bool wantsExit() const;
};

#endif
