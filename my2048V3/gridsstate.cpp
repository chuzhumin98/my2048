#include "gridsstate.h"
#include <fstream>

GridsState::GridsState()
{
    grids = new Grid* [4];
    for (int i = 0; i < 4; i++) {
        grids[i] = new Grid [4];
    }
    score = 0;
}

GridsState::~GridsState() {
    for (int i = 0; i < 4; i++) {
        delete []grids[i];
    }
    delete []grids;
}

GridsState::GridsState(const GridsState &gs) {
    grids = new Grid* [4];
    for (int i = 0; i < 4; i++) {
        grids[i] = new Grid [4];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grids[i][j].setAs(gs.grids[i][j]);
        }
    }
    this->score = gs.score;
    this->lb.setAs(gs.lb);
}

void GridsState::setAs(const GridsState &gs) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grids[i][j].setAs(gs.grids[i][j]);
        }
    }
    this->score = gs.score;
    this->lb.setAs(gs.lb);
}

void GridsState::setZero() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grids[i][j].setValue(0);
        }
    }
    this->score = 0;
    this->lb.setZero();
}

bool GridsState::operator ==(const GridsState &gs) const {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grids[i][j].getValue() != gs.grids[i][j].getValue()) {
                return false;
            }
        }
    }
    return true;
}

bool GridsState::gameiswin(int winnum) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->grids[i][j].getValue() >= winnum) return true;
        }
    }
    return false;
}

bool GridsState::gameisover() {
    bool isfull = this->gameistotalfull();
    if (!isfull) return false;
    if (this->lb.isExcited()) {
        if (this->lb.isLove()) {
            return false;
        } else {
            int x = -1, y = -1;
            this->getLoveBreak(x, y);
            if (x >= 1) {
                if (this->grids[x-1][y].getValue() >= 4) return false;
            }
            if (x >= 0 && x < 3) {
                if (this->grids[x+1][y].getValue() >= 4) return false;
            }
            if (y >= 1) {
                if (this->grids[x][y-1].getValue() >= 4) return false;
            }
            if (y >= 0 && y < 3) {
                if (this->grids[x][y+1].getValue() >= 4) return false;
            }
        }
    }
    return true;
}

void GridsState::draw() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->grids[i][j].setLabel();
        }
    }
    //grids[2][2].setLabelsmall();
}

void GridsState::readFromFile() {
    std::ifstream finsave;
    finsave.open("gamecache.txt");
    finsave >> this->score;
    int num1, num2;
    finsave >> num1 >> num2;
    this->lb.setLove(num1);
    this->lb.setBreak(num2);
    int tmp = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            finsave >> tmp;
            this->grids[i][j].setValue(tmp);
        }
    }
    finsave.close();
}

int GridsState::getMax() {
    int maxes = 2;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->grids[i][j].getValue() > maxes && this->grids[i][j].getValue() != 3) {
                maxes = this->grids[i][j].getValue();
            }
        }
    }
    return maxes;
}

void GridsState::getLoveBreak(int &x, int &y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->grids[i][j].getValue() == 1) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

void GridsState::deletelovebreak() {
    int x = -1, y = -1;
    this->getLoveBreak(x, y);
    if (x != -1 && y != -1) {
        this->grids[x][y].setValue(0);
    }
}

bool GridsState::gameistotalfull() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->grids[i][j].getValue() == 0) return false;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != 0) {
                if (this->grids[i][j].getValue() == this->grids[i-1][j].getValue()) return false;
            }
            if (i != 3) {
                if (this->grids[i][j].getValue() == this->grids[i+1][j].getValue()) return false;
            }
            if (j != 0) {
                if (this->grids[i][j].getValue() == this->grids[i][j-1].getValue()) return false;
            }
            if (j != 3) {
                if (this->grids[i][j].getValue() == this->grids[i][j+1].getValue()) return false;
            }
        }
    }
    return true;
}

int GridsState::CountGarbage() {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->grids[i][j].getValue() == 3) {
                count++;
            }
        }
    }
    return count;
}
