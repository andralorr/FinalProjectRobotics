#include "LcdRenderer.h"

byte heartChar[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

LcdRenderer::LcdRenderer(LiquidCrystal* l) : lcd(l) {
    lcd->createChar(0, heartChar);
}

void LcdRenderer::showMenu(uint8_t index) {
    lcd->clear();

    const char* items[] = {
        "Learn",
        "FreePlay",
        "Game"
    };

    uint8_t next = (index + 1) % 3;

    lcd->setCursor(0, 0);
    lcd->print("> ");
    lcd->print(items[index]);

    lcd->setCursor(0, 1);
    lcd->print("  ");
    lcd->print(items[next]);
}

void LcdRenderer::showLearn(const char* name, uint8_t targetOct, uint8_t currentOct, uint8_t step, uint8_t total) {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(name);
    lcd->print(" ");
    lcd->print(step + 1);
    lcd->print("/");
    lcd->print(total);

    lcd->setCursor(0, 1);
    lcd->print("GO TO O:");
    lcd->print(targetOct);
    
    lcd->setCursor(10, 1);
    lcd->print("NOW:");
    lcd->print(currentOct);
}

void LcdRenderer::showCongratulation() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("   EXCELLENT!   ");
    lcd->setCursor(0, 1);
    lcd->print(" SONG FINISHED  ");
}

void LcdRenderer::showFreePlay() {
    lcd->setCursor(0, 0);
    lcd->print("FREE PLAY      ");
    lcd->setCursor(0, 1);
    lcd->print("Improvise  ");
}

void LcdRenderer::clear() {
    lcd->clear();
}

void LcdRenderer::showFreePlayDetail(uint8_t octave, uint8_t waveform, bool sustain, bool recording, int loopCount) {
    lcd->setCursor(0, 0);
    if (recording) {
        lcd->print("RECORDING...    ");
    } else if (loopCount > 0) {
        lcd->print("SINGING...      ");
    } else {
        lcd->print("FREE PLAY       ");
    }
    
    lcd->setCursor(0, 1);
    lcd->print(sustain ? "S " : "  "); 
    lcd->print("Oct:");
    lcd->print(octave + 3);
    lcd->print(" ");
    
    switch(waveform) {
        case 0: lcd->print("Normal  "); break;
        case 1: lcd->print("Vibrato "); break;
        case 2: lcd->print("Staccato"); break;
    }
}

void LcdRenderer::showSongPicker(const char* songName, uint8_t current, uint8_t total) {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("SELECT SONG:");
    lcd->setCursor(0, 1);
    lcd->print("< ");
    lcd->print(songName);
    lcd->print(" >");
    
    lcd->setCursor(13, 0);
    lcd->print(current + 1);
    lcd->print("/");
    lcd->print(total);
}

void LcdRenderer::showGameReady(const char* trackName) {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("SONG:");
    lcd->print(trackName);

    lcd->setCursor(0, 1);
    lcd->print("Press to start");
}

void LcdRenderer::showGameStatus(uint8_t lives) {
    lcd->setCursor(0, 0);
    lcd->print("HAVE FUN     ");

    lcd->setCursor(10, 1);

    for (uint8_t i = 0; i < lives; i++) {
        lcd->write(byte(0));
    }

    for (uint8_t i = lives; i < 3; i++) {
        lcd->print(" ");
    }
}

void LcdRenderer::showGameOver() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("GAME OVER");

    lcd->setCursor(0, 1);
    lcd->print("Try again");
}

void LcdRenderer::showCountdown(uint8_t value) {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Starting in...");

    lcd->setCursor(7, 1);
    lcd->print(value);
}