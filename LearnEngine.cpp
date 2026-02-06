#include "LearnEngine.h"

LearnEngine::LearnEngine(InputController* in, LcdRenderer* l) {
    input = in;
    lcd = l;
}

void LearnEngine::init() {
    clearLeds();
    state = SELECT_SONG;
    selectedSong = 0;
    step = 0;
    exitRequested = false;
    currentOctave = 3;
    showSongSelect();
}

void LearnEngine::update() {
    if (notePlaying && millis() - noteStartTime >= currentNoteDuration) {
        noTone(buzzerPin);
        notePlaying = false;
    }

    if (state != FINISHED && input->isPressed()) {
        unsigned long clickTime = millis();
        if (clickTime - lastClickTime < 400) {
            exitRequested = true;
            return;
        }
        lastClickTime = clickTime;
    }

    switch (state) {
        case SELECT_SONG: updateSongSelect(); break;
        case PLAY_STEP: updatePlayStep(); break;
        case FINISHED:
            lastLedNote = -1;
            clearLeds();
            unsigned long lastFinishPress = 0;
            if (input->isPressed() && millis() - lastFinishPress > 500) {
                lastFinishPress = millis();
                init();
            }
            break;
    }
}

void LearnEngine::updateSongSelect() {
    unsigned long now = millis();
    
    if (now - lastJoystickMove > 250) {
        if (input->isJoystickLeft() && selectedSong > 0) {
            selectedSong--;
            lastJoystickMove = now;
            showSongSelect();
        } 
        else if (input->isJoystickRight() && selectedSong < learnSeqCount - 1) {
            selectedSong++;
            lastJoystickMove = now;
            showSongSelect();
        }
    }

    if (input->isPressed()) {
        clearLeds();
        lastLedNote = -1;
        seq = &learnSeq[selectedSong];
        state = PLAY_STEP;
        step = 0;
        lcd->clear();
        showPlayStep();
    }
}

void LearnEngine::updatePlayStep() {
    const LearnNote& target = seq->notes[step];
    unsigned long now = millis();

    if (now - lastJoystickMove > 300) {
        if (input->isJoystickLeft() && currentOctave > 3) {
            currentOctave--;
            lastJoystickMove = now;
            showPlayStep();
        } else if (input->isJoystickRight() && currentOctave < 5) {
            currentOctave++;
            lastJoystickMove = now;
            showPlayStep();
        }
    }

    if (lastLedNote != target.noteIndex) {
        clearLeds();
        digitalWrite(ledPins[target.noteIndex], HIGH);
        lastLedNote = target.noteIndex;
    }

    if (input->isButtonDown(target.noteIndex) && !notePlaying) {
        uint8_t freqIndex = currentOctave - 3;
        if (freqIndex < 3) {
            tone(buzzerPin, note_frequencies[target.noteIndex][freqIndex]);
            notePlaying = true;
            noteStartTime = millis();
        }

        if (currentOctave == target.octave) {
            step++;
            lastLedNote = -1;

            if (step >= seq->length) {
                state = FINISHED;
                clearLeds();
                lcd->showCongratulation();
            } else {
                showPlayStep();
            }
        }
    }
}

void LearnEngine::showSongSelect() {
    lcd->showSongPicker(learnSeq[selectedSong].name, selectedSong, learnSeqCount);
}

void LearnEngine::showPlayStep() {
    uint8_t targetOct = seq->notes[step].octave;
  
    lcd->showLearn(seq->name, targetOct, currentOctave, step, seq->length);
}

bool LearnEngine::wantsExit() const {
    return exitRequested;
}

void LearnEngine::clearLeds() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], LOW);
    }
}

void LearnEngine::stop() {
    noTone(buzzerPin);
    notePlaying = false;
    clearLeds();
    lastLedNote = -1;
}