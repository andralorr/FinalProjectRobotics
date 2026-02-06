#ifndef LCDRENDERER_H
#define LCDRENDERER_H

#include <LiquidCrystal.h>
#include <Arduino.h>

class LcdRenderer {
private:
    LiquidCrystal* lcd;
    
public:
    LcdRenderer(LiquidCrystal* lcd);

    void clear(); 
    void showMenu(uint8_t selection);
    void showLearn(const char* name, uint8_t targetOct, uint8_t currentOct, uint8_t step, uint8_t total);
    void showSongPicker(const char* songName, uint8_t current, uint8_t total);
    void showCongratulation();
    void showFreePlay();
    void showFreePlayDetail(uint8_t octave, uint8_t waveform, bool sustain, bool recording, int loopCount);
    void showGameReady(const char* name);
    void showGameStatus(uint8_t lives);
    void showGameOver();
    void showCountdown(uint8_t value);

};

#endif
