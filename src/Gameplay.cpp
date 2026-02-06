#include "Gameplay.h"
#include "GameplayTracks.h"

Gameplay::Gameplay(InputController* in, LcdRenderer* l) : input(in), lcd(l) {}

void Gameplay::enterSelector() {
    selectedTrack = 0;
    exitRequested = false;
    state = GAME_READY;

    currentTrack = nullptr;
    noteIndex = 0;
    lives = 3;
    noteActive = false;

    noTone(buzzerPin);
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }

    lcd->clear();
    lcd->showGameReady(game_tracks[selectedTrack].name);
}

void Gameplay::update() {

    if (input->isPressed()) {
      unsigned long now = millis();
      if (now - lastClickTime < 400) {
        exitRequested = true;
        return;
      }
      lastClickTime = now;
    }

    switch (state) {

      case GAME_READY: {
        if (inCountdown) {
          unsigned long now = millis();

          if (now - countdownStart >= 1000) {
            countdownStart = now;
            if (countdownValue > 0) {
              countdownValue--;
            }

            if (countdownValue == 0) {
              inCountdown = false;
              state = GAME_PLAYING;
              lcd->clear();
              lcd->showGameStatus(lives);
            } else {
              lcd->showCountdown(countdownValue);
            }
          }
          return;
        }
        unsigned long now = millis();

        if (now - lastNavTime > 250) {
          if (input->isJoystickLeft()) {
            selectedTrack = (selectedTrack == 0) ? game_tracks_count - 1 : selectedTrack - 1;
            lcd->showGameReady(game_tracks[selectedTrack].name);
            lastNavTime = now;
          }
          else if (input->isJoystickRight()) {
            selectedTrack = (selectedTrack + 1) % game_tracks_count;

            lcd->showGameReady(game_tracks[selectedTrack].name);
            lastNavTime = now;
          }
        }

        if (input->isPressed()) {
          startGame(&game_tracks[selectedTrack]);
        }
        break;
      }

      case GAME_PLAYING:

        if (!noteActive) {
          startNote();
        }

        handleInput();
        checkTimeout();

        if (finishingLastNote) {
          if (millis() - lastNoteStartTime >= last_note_duration) {
              finishingLastNote = false;

              state = GAME_WIN;
              noTone(buzzerPin);

              for (int i = 0; i < 4; i++) {
                digitalWrite(ledPins[i], LOW);
              }

              lcd->showCongratulation();
              return;
            }
        }
        break;

      case GAME_OVER:
        if (input->isPressed()) {
          exitRequested = true;
        }
        break;

      case GAME_WIN:
        if (input->isPressed()) {
            exitRequested = true;
        }
        break;
    }
}

void Gameplay::startGame(const GameTrack* track) {
    currentTrack = track;
    state = GAME_READY;

    noteIndex = 0;
    lives = 3;
    noteActive = false;

    inCountdown = true;
    countdownStart = millis();
    countdownValue = 3;

    noTone(buzzerPin);
    lcd->showCountdown(countdownValue);
}


void Gameplay::startNote() {
    if (!currentTrack) return;

    if (noteIndex >= currentTrack->length) {
        state = GAME_WIN;
        noTone(buzzerPin);
        lcd->showCongratulation();
        return;
    }

    const GameNote& note = currentTrack->notes[noteIndex];

    noteStartTime = millis();
    noteActive = true;

    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }
    digitalWrite(ledPins[note.btn], HIGH);
}


void Gameplay::handleInput() {
    if (!noteActive) return;

    const GameNote& note = currentTrack->notes[noteIndex];

    if (input->isButtonDown(note.btn)) {
        tone(buzzerPin, note.freq, 120);
        finishNote(true);
    }
}


void Gameplay::checkTimeout() {
    if (!noteActive || finishingLastNote) return;

    const GameNote& note = currentTrack->notes[noteIndex];

    if (millis() - noteStartTime > note.windowMs) {
        lives--;
        finishNote(false);
    }
}

void Gameplay::finishNote(bool success) {
    noteActive = false;

    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }

    noteIndex++;

    lcd->showGameStatus(lives);

    if (lives == 0) {
        gameOver();
    }
}

void Gameplay::gameOver() {
    state = GAME_OVER;
    noTone(buzzerPin);

    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }

    lcd->showGameOver();
}


void Gameplay::stop() {
    noTone(buzzerPin);
    noteActive = false;

    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }
}

bool Gameplay::wantsExit() const {
    return exitRequested;
}
