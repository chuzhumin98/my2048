#ifndef GRIDSSTATE_H
#define GRIDSSTATE_H
#include "grid.h"
#include "lovebreak.h"

class GridsState
{
public:
    Grid** grids;
    LoveBreak lb;
    GridsState();
    ~GridsState();
    GridsState(const GridsState &gs);
    void setScore(int sc) { score = sc; }
    int getScore() { return score; }
    void addScore(int num) {
        score += num;
        if (score < 0) score = 0;
    }
    void setAs(const GridsState &gs);
    void setZero();
    bool operator ==(const GridsState &gs) const;
    bool operator !=(const GridsState &gs) const {
        return !(*this == gs);
    }
    bool gameiswin(int winnum);
    bool gameisover();
    bool gameistotalfull();
    void draw();
    int getMax();
    // =; gamecache.txt
    void readFromFile();
    void getLoveBreak(int &x, int &y);
    void deletelovebreak();
    int CountGarbage();

private:

    int score;
};

#endif // GRIDSSTATE_H
