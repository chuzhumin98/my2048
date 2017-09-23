#ifndef GRIDS_H
#define GRIDS_H
#include "grid.h"
#include "gridsstate.h"
#include <QGridLayout>
#include <ctime>
#include <lovebreak.h>

enum Direction { UP = 0, DOWN, LEFT, RIGHT };
class Grids
{
public:
    QGridLayout *boardLayout;
    void setBoardLayout();
    Grids();    
    ~Grids();
    Grids(const Grids &g);
    void draw();
    bool move(Direction d);
    int hasNum(int num, int* values);
    void simplify(int* values, int &curlen, int &bonus, int* needbig);
    bool setA2(int &x, int &y);
    void backtopred();
    void setScore(int sc) {
        this->gsnow.setScore(sc);
    }
    int getScore() {
        return this->gsnow.getScore();
    }
    void setBackleft(int bl) { backleft = bl; }
    int getBackleft() { return backleft; }
    void reset();
    bool gameisover(); // true for game is over
    bool gameiswin(); // true for game is win
    bool canbeback() { return ((gsnow != gspred) && (backleft > 0)); }
    void getLoveBreak(int &x, int &y) { this->gsnow.getLoveBreak(x, y); }
    void deletelovebreak() { this->gsnow.deletelovebreak(); }
    GridsState& getgsnow() { return gsnow; }

private:
    GridsState gsnow;
    GridsState gspred;
    const int winnum;
    int backleft;
};

#endif // GRIDS_H
