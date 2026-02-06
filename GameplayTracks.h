#ifndef GAMEPLAYTRACKS_H
#define GAMEPLAYTRACKS_H

#include "Gameplay.h"
#include "Frequencies.h"

const GameNote track_odejoy[] = {

    {2, NOTE_E4, 1000},
    {0, NOTE_E4, 1000},
    {3, NOTE_F4, 1000},
    {1, NOTE_G4, 1000},

    {3, NOTE_G4, 1000},
    {3, NOTE_F4, 1000},
    {2, NOTE_E4, 1000},
    {1, NOTE_D4, 1000},

    {0, NOTE_C4, 1000},
    {2, NOTE_C4, 1000},
    {1, NOTE_D4, 1000},
    {2, NOTE_E4, 1000},

    {2, NOTE_E4, 1500},
    {1, NOTE_D4, 600},
    {1, NOTE_D4, 2000},

    {2, NOTE_E4, 1000},
    {2, NOTE_E4, 1000},
    {3, NOTE_F4, 1000},
    {1, NOTE_G4, 1000},

    {3, NOTE_G4, 1000},
    {3, NOTE_F4, 1000},
    {2, NOTE_E4, 1000},
    {1, NOTE_D4, 1000},

    {0, NOTE_C4, 1000},
    {3, NOTE_C4, 1000},
    {1, NOTE_D4, 1000},
    {2, NOTE_E4, 1000},

    {1, NOTE_D4, 1500},
    {0, NOTE_C4, 600},
    {0, NOTE_C4, 2000},

    {1, NOTE_D4, 1000},
    {1, NOTE_D4, 1000},
    {2, NOTE_E4, 1000},
    {0, NOTE_C4, 1000},

    {1, NOTE_D4, 1000},
    {2, NOTE_E4, 600},
    {3, NOTE_F4, 600},
    {2, NOTE_E4, 1000},
    {0, NOTE_C4, 1000},

    {1, NOTE_D4, 1000},
    {2, NOTE_E4, 600},
    {3, NOTE_F4, 600},
    {2, NOTE_E4, 1000},
    {1, NOTE_D4, 1000},

    {0, NOTE_C4, 1000},
    {1, NOTE_D4, 1000},
    {0, NOTE_G3, 2000},

    {2, NOTE_E4, 1000},
    {2, NOTE_E4, 1000},
    {3, NOTE_F4, 1000},
    {3, NOTE_G4, 1000},

    {3, NOTE_G4, 1000},
    {3, NOTE_F4, 1000},
    {2, NOTE_E4, 1000},
    {1, NOTE_D4, 1000},

    {0, NOTE_C4, 1000},
    {0, NOTE_C4, 1000},
    {1, NOTE_D4, 1000},
    {2, NOTE_E4, 1000},

    {1, NOTE_D4, 1500},
    {0, NOTE_C4, 600},
    {0, NOTE_C4, 2000}
};

const GameNote track_silentnight[] = {

    {3, NOTE_G4, 1500},
    {2, NOTE_A4, 600},
    {3, NOTE_G4, 1000},
    {2, NOTE_E4, 3000},

    {3, NOTE_G4, 1500},
    {2, NOTE_A4, 600},
    {3, NOTE_G4, 1000},
    {2, NOTE_E4, 3000},

    {1, NOTE_D5, 2000},
    {1, NOTE_D5, 1000},
    {1, NOTE_B4, 3000},

    {0, NOTE_C5, 2000},
    {0, NOTE_C5, 1000},
    {3, NOTE_G4, 3000},

    {2, NOTE_A4, 2000},
    {2, NOTE_A4, 1000},
    {0, NOTE_C5, 1500},
    {1, NOTE_B4, 600},
    {2, NOTE_A4, 1000},

    {3, NOTE_G4, 1500},
    {2, NOTE_A4, 600},
    {3, NOTE_G4, 1000},
    {2, NOTE_E4, 3000},

    {2, NOTE_A4, 2000},
    {2, NOTE_A4, 1000},
    {0, NOTE_C5, 1500},
    {1, NOTE_B4, 600},
    {2, NOTE_A4, 1000},

    {3, NOTE_G4, 1500},
    {2, NOTE_A4, 600},
    {3, NOTE_G4, 1000},
    {2, NOTE_E4, 3000},

    {1, NOTE_D5, 2000},
    {1, NOTE_D5, 1000},
    {3, NOTE_F5, 1500},
    {1, NOTE_D5, 600},
    {1, NOTE_B4, 1000},

    {0, NOTE_C5, 3000},
    {2, NOTE_E5, 3000},

    {0, NOTE_C5, 1000},
    {3, NOTE_G4, 1000},
    {2, NOTE_E4, 1000},

    {3, NOTE_G4, 1500},
    {3, NOTE_F4, 600},
    {1, NOTE_D4, 1000},

    {0, NOTE_C4, 3000},
    {0, NOTE_C4, 4000}
};

const GameTrack game_tracks[] = {
    { "ODE TO JOY", track_odejoy, sizeof(track_odejoy) / sizeof(GameNote) },
    { "SILENT", track_silentnight, sizeof(track_silentnight) / sizeof(GameNote) }
};

const uint8_t game_tracks_count =
    sizeof(game_tracks) / sizeof(GameTrack);

#endif
