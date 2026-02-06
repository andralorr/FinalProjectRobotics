#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <Arduino.h>
#include "InputController.h"
#include "LcdRenderer.h"
#include "Config.h"

struct GameNote {
    uint8_t btn;       
    uint16_t freq;
    uint16_t windowMs; 
};

struct GameTrack {
    const char* name;
    const GameNote* notes;
    uint16_t length;
};

enum GameplayState {
    GAME_READY,
    GAME_PLAYING,
    GAME_OVER,
    GAME_WIN
};

class Gameplay {

private:
    InputController* input;
    LcdRenderer* lcd;

    const GameTrack* currentTrack = nullptr;

    uint16_t noteIndex = 0;
    unsigned long noteStartTime = 0;
    bool noteActive = false;

    GameplayState state = GAME_READY;
    uint8_t lives = 3;

    uint8_t selectedTrack = 0;

    unsigned long lastClickTime = 0;
    unsigned long lastNavTime = 0;

    bool exitRequested = false;
    bool soundActive = false;
    unsigned long soundStartTime = 0;
    bool finishingLastNote = false;
    unsigned long lastNoteStartTime = 0;
    static const unsigned long last_note_duration = 300;
    bool inCountdown = false;
    unsigned long countdownStart = 0;
    uint8_t countdownValue = 3;

    void startNote();
    void handleInput();
    void checkTimeout();
    void finishNote(bool success);
    void gameOver();
    void startGame(const GameTrack* track);
    
public:
    Gameplay(InputController* in, LcdRenderer* lcd);

    void update();
    void stop();
    bool wantsExit() const;
    void enterSelector();

};


#endif
