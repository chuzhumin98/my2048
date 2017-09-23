#ifndef SAVEGAME_H
#define SAVEGAME_H
#include "gridsstate.h"

// file name: gamecache.txt
class SaveGame
{
public:   
    SaveGame(GridsState &gs);
    void saveAsthis();

private:
    GridsState mygs;
};

#endif // SAVEGAME_H
