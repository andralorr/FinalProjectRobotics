#ifndef MELODIES_H
#define MELODIES_H

#include <Arduino.h>

struct LearnNote {
    uint8_t noteIndex;
    uint8_t octave;
};

struct LearnSequence {
    const char* name;
    const LearnNote* notes;
    uint8_t length;
};

extern const LearnSequence learnSeq[];
extern const uint8_t learnSeqCount;

#endif
