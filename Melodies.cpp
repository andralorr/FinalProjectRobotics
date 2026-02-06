#include "Melodies.h"

const LearnNote ASCENT[] = {
    {0,4}, {1,4}, {2,4}, {3,4},
    {2,4}, {1,4}, {0,4},
    {0,5}, {1,5}, {2,5},
    {1,5}, {0,5},
    {0,4}, {1,4}, {0,4}
};

const LearnNote ECHO[] = {
    {0,4}, {2,4}, {0,4},
    {0,5}, {2,5}, {0,5},
    {1,4}, {3,4}, {1,4},
    {1,5}, {3,5}, {1,5},
    {0,4}, {0,4}
};


const LearnNote WAVE[] = {
    {1,4}, {2,4}, {3,4}, {2,4},
    {1,4}, {0,4}, {1,4},
    {2,4}, {3,4}, {2,4}, {1,4},
    {0,4}, {1,4},
    {1,5}, {2,5}, {1,5}, {0,5},
    {0,4}
};

const LearnNote CALL_ANSWER[] = {
    {0,4}, {1,4}, {2,4},
    {1,4}, {0,4},
    {2,4}, {3,4}, {2,4},
    {1,4},
    {0,5}, {1,5}, {0,5},
    {2,4}, {1,4}, {0,4}
};

const LearnNote GROUND_SKY[] = {
    {0,3}, {1,3}, {2,3}, {1,3}, {0,3},
    {0,4}, {1,4}, {2,4}, {3,4},
    {2,4}, {1,4}, {0,4},
    {1,5}, {2,5}, {1,5},
    {0,4}
};

const LearnSequence learnSeq[] = {
    { "ASCENT", ASCENT, sizeof(ASCENT) / sizeof(LearnNote) },
    { "ECHO", ECHO, sizeof(ECHO) / sizeof(LearnNote) },
    { "WAVE", WAVE, sizeof(WAVE) / sizeof(LearnNote) },
    { "CALL&ANSW", CALL_ANSWER, sizeof(CALL_ANSWER) / sizeof(LearnNote) },
    { "GROUND-SKY", GROUND_SKY, sizeof(GROUND_SKY) / sizeof(LearnNote) }
};

const uint8_t learnSeqCount =
    sizeof(learnSeq) / sizeof(LearnSequence);
