#ifndef LEARNENGINE_H
#define LEARNENGINE_H

#include "InputController.h"
#include "LcdRenderer.h"
#include "Config.h"
#include "Melodies.h"

enum LearnState {
    SELECT_SONG,
    PLAY_STEP,
    FINISHED
};


class LearnEngine {

private:
    
    InputController* input;
    LcdRenderer* lcd;

    LearnState state = SELECT_SONG;
    uint8_t selectedSong = 0;
    const LearnSequence* seq = nullptr;
    uint8_t step = 0;

    uint8_t currentOctave;
    unsigned long lastJoystickMove = 0;
    unsigned long lastClickTime = 0;
    bool exitRequested = false;
    int8_t lastLedNote = -1;
    bool notePlaying = false;
    unsigned long noteStartTime = 0;
    const unsigned long currentNoteDuration = 220;

    void updateSongSelect();
    void updatePlayStep();
    void showSongSelect();
    void showPlayStep();
    void handleExit();
    void clearLeds();

public:
    LearnEngine(InputController* in, LcdRenderer* lcd);
    void init();
    void update();
    bool wantsExit() const;
    void stop();
};

#endif
