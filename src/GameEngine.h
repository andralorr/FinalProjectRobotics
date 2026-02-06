#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Config.h"
#include "InputController.h"
#include "LcdRenderer.h"
#include "Melodies.h"
#include "FreePlayEngine.h"
#include "LearnEngine.h"
#include "Gameplay.h"
#include "GameplayTracks.h"

enum GameState { MENU, LEARN, FREE_PLAY, GAMEPLAY };

class GameEngine {

private:
    void updateMenu();

    InputController* input;
    LcdRenderer* lcd;
    FreePlayEngine* freePlay;
    LearnEngine* learn;
    Gameplay* gameplay; 

    GameState currentState;
    uint8_t menuIndex;

public:
    GameEngine(InputController* inp, LcdRenderer* lcdRend);
    void init();
    void update();
};

#endif
