#include "savegame.h"
#include <fstream>

SaveGame::SaveGame(GridsState &gs) {
    mygs.setAs(gs);
}

void SaveGame::saveAsthis() {
    std::ofstream foutsave;
    foutsave.open("gamecache.txt");
    foutsave << mygs.getScore() << " " << mygs.lb.getLove() << " " << mygs.lb.getBreak() << " ";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            foutsave << mygs.grids[i][j].getValue() << " ";
        }
    }
    foutsave.close();
}

