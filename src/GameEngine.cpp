#include "GameEngine.h"

GameEngine::GameEngine(InputController* inp, LcdRenderer* lcdRend)
: input(inp), lcd(lcdRend) {
    currentState = MENU;
    menuIndex = 0;
    freePlay = new FreePlayEngine(input, lcd);
    learn = new LearnEngine(input, lcd);
    gameplay = new Gameplay(input, lcd);
}

void GameEngine::init() {
    pinMode(buzzerPin, OUTPUT);

    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }

    input->init();
    lcd->showMenu(menuIndex);
}

void GameEngine::update() {
    switch (currentState) {
        case MENU:
            updateMenu();
            break;

        case LEARN:
            learn->update();
            if (learn->wantsExit()) {
                learn->stop();  
                currentState = MENU;
                lcd->clear();
                lcd->showMenu(menuIndex);
            }
            break;

        case FREE_PLAY:
            freePlay->update();
            if (freePlay->wantsExit()) {
                currentState = MENU;
                lcd->clear();
                lcd->showMenu(menuIndex);
            }
            break;

        case GAMEPLAY:
            gameplay->update();
            if (gameplay->wantsExit()) {
                gameplay->stop();
                currentState = MENU;
                lcd->clear();
                lcd->showMenu(menuIndex);
            }
            break;
    }
}

void GameEngine::updateMenu() {

    if (input->movedDown()) {
        menuIndex = (menuIndex + 1) % 3;
        lcd->showMenu(menuIndex);
    }

    if (input->movedUp()) {
        menuIndex = (menuIndex + 2) % 3; 
        lcd->showMenu(menuIndex);
    }

    if (!input->isPressed()) return;

    lcd->clear();

    switch (menuIndex) {
        case 0:
            currentState = LEARN;
            learn->init();
            break;

        case 1:
            currentState = FREE_PLAY;
            freePlay->init();
            break;

        case 2:
            gameplay->enterSelector();
            currentState = GAMEPLAY;
            break;
    }
}

