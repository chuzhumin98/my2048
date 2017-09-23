#include "grids.h"

void Grids::setBoardLayout() {
    for (int i = 0; i < 4; i++) {
        this->boardLayout->setRowMinimumHeight(i, 95);
        this->boardLayout->setColumnMinimumWidth(i, 210);
    }
    this->boardLayout->setSpacing(0);
}

Grids::Grids(): winnum(2048)
{
    this->boardLayout = new QGridLayout;
    srand(time(0));
    backleft = 3;
    int tmp1 = rand()%16;
    int tmp2 = rand()%16;
    this->gsnow.grids[tmp1/4][tmp1%4].setValue(2);
    this->gsnow.grids[tmp2/4][tmp2%4].setValue(2);

/*    this->gsnow.grids[0][0].setValue(1);
    this->gsnow.grids[0][1].setValue(4);
    this->gsnow.grids[0][2].setValue(2);
    this->gsnow.grids[0][3].setValue(4);
    this->gsnow.grids[1][0].setValue(4);
    this->gsnow.grids[1][1].setValue(2);
    this->gsnow.grids[1][2].setValue(4);
    this->gsnow.grids[1][3].setValue(2);
    this->gsnow.grids[2][0].setValue(2);
    this->gsnow.grids[2][1].setValue(4);
    this->gsnow.grids[2][2].setValue(2);
    this->gsnow.grids[2][3].setValue(4);
    this->gsnow.grids[3][0].setValue(4);
    this->gsnow.grids[3][1].setValue(2);
    this->gsnow.grids[3][2].setValue(4);
    this->gsnow.grids[3][3].setValue(2);
    this->gsnow.lb.setLove(5);
    this->gsnow.lb.setBreak(2); */

    this->gsnow.readFromFile();

/*    int num = 2;
    for (int i = 0; i < 16; i++) {
        this->gsnow.grids[i/4][i%4].setValue(num);
        num *= 2;
    } */

    this->gspred.setAs(this->gsnow);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardLayout->addWidget(&this->gsnow.grids[i][j], i, j, Qt::AlignCenter);
        }
    }
    this->setBoardLayout();
}

Grids::Grids(const Grids &g): winnum(2048) {
    this->boardLayout = new QGridLayout;
    backleft = g.backleft;
    this->gsnow.setAs(g.gsnow);
    this->gspred.setAs(g.gspred);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardLayout->addWidget(&this->gsnow.grids[i][j], i, j, Qt::AlignCenter);
        }
    }
    this->setBoardLayout();
}

Grids::~Grids() {
    delete this->boardLayout;
}

void Grids::draw() {
    this->gsnow.draw();
    if (this->gsnow.lb.isExcited()) {
        int x = -1, y = -1;
        this->getLoveBreak(x, y);
        if (x != -1 && y != -1) {
            bool isLoved = this->gsnow.lb.isLove();
            if (isLoved) {
                this->gsnow.grids[x][y].setLoveorBreak(isLoved, this->gsnow.lb.getLove());
            } else {
                this->gsnow.grids[x][y].setLoveorBreak(isLoved, this->gsnow.lb.getBreak());
            }
        }
    }
}

// return if the grid is exactly moved
bool Grids::move(Direction d) {
    Grids initialVersion(*this);
    int* values = new int [4];
    int* needbig = new int [4];
    int bonus = 0;
    if (d == UP) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                values[j] = this->gsnow.grids[j][i].getValue();
            }
            int sign = 4;
            simplify(values, sign, bonus, needbig);
            for (int j = 0; j < 4; j++) {
                if (needbig[j]) {
                    this->gsnow.grids[j][i].startThreadtoBig();
                }
            }
            for (int j = 0; j < sign; j++) {
                this->gsnow.grids[j][i].setValue(values[j]);
            }
            for (int j = sign; j < 4; j++) {
                this->gsnow.grids[j][i].setValue(0);
            }
        }
    }
    if (d == DOWN) {
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 0; j--) {
                values[3-j] = this->gsnow.grids[j][i].getValue();
            }
            int sign = 4;
            simplify(values, sign, bonus, needbig);
            for (int j = 0; j < 4; j++) {
                if (needbig[j]) {
                    this->gsnow.grids[3-j][i].startThreadtoBig();
                }
            }
            for (int j = 3; j > 3 - sign; j--) {
                this->gsnow.grids[j][i].setValue(values[3-j]);
            }
            for (int j = 3 - sign; j >= 0; j--) {
                this->gsnow.grids[j][i].setValue(0);
            }
        }
    }
    if (d == LEFT) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                values[j] = this->gsnow.grids[i][j].getValue();
            }
            int sign = 4;
            simplify(values, sign, bonus, needbig);
            for (int j = 0; j < 4; j++) {
                if (needbig[j]) {
                    this->gsnow.grids[i][j].startThreadtoBig();
                }
            }
            for (int j = 0; j < sign; j++) {
                this->gsnow.grids[i][j].setValue(values[j]);
            }
            for (int j = sign; j < 4; j++) {
                this->gsnow.grids[i][j].setValue(0);
            }
        }
    }
    if (d == RIGHT) {
        for (int i = 0; i < 4; i++) {           
            for (int j = 3; j >= 0; j--) {
                values[3-j] = this->gsnow.grids[i][j].getValue();
            }
            int sign = 4;
            simplify(values, sign, bonus, needbig);
            for (int j = 0; j < 4; j++) {
                if (needbig[j]) {
                    this->gsnow.grids[i][3-j].startThreadtoBig();
                }
            }
            for (int j = 3; j > 3 - sign; j--) {
                this->gsnow.grids[i][j].setValue(values[3-j]);
            }
            for (int j = 3 - sign; j >= 0; j--) {
                this->gsnow.grids[i][j].setValue(0);
            }
        }
    }
    bool haschanged = (this->gsnow != initialVersion.gsnow);
    if (!haschanged) {
        if (this->gsnow.gameistotalfull() && this->gsnow.lb.isLove()) {
            int x = -1, y = -1;
            this->getLoveBreak(x, y);
            if (d == UP) {
                x--;
            }
            if (d == DOWN) {
                x++;
            }
            if (d == LEFT) {
                y--;
            }
            if (d == RIGHT) {
                y++;
            }
            if (x >= 0 && x <= 3 && y >= 0 && y <= 3 && this->gsnow.grids[x][y].getValue() != 3) {
                this->gsnow.grids[x][y].mulValue();
                this->gsnow.grids[x][y].startThreadtoBig();
                this->gsnow.lb.addBreak();
                bonus += this->gsnow.grids[x][y].getValue();
                haschanged = true;
            }
        }
    }
    this->gsnow.addScore(bonus);
    if (haschanged) {
        if (this->gsnow.lb.isLove()) {
            this->gsnow.lb.subLove();
            if (this->gsnow.lb.isfinished()) {
                this->deletelovebreak();
            }
        }
        if (this->gsnow.lb.isfinished()) {
            this->deletelovebreak();
        }
        int x = -1, y = -1;
        bool isOK = setA2(x, y);
        if (isOK) {
            this->gsnow.grids[x][y].startThreadtoSmall();
        }
        this->gspred.setAs(initialVersion.gsnow);
    }
    delete []values;
    delete []needbig;
    return haschanged;
}

int Grids::hasNum(int num, int *values) {
    for (int i = 0; i < 4; i++) {
        if (values[i] == num) return i;
    }
    return -1;
}

void Grids::simplify(int *values, int &curlen, int &bonus, int* needbig) {
    int has1pred = hasNum(1, values);
    int sign = 0;
    for (int i = 0; i < 4; i++) {
        needbig[i] = 0;
    }
    for (int i = 0; i < curlen; i++) {
        if (values[i] != 0) {
            values[sign] = values[i];
            sign++;
        }
    }
    int pred_length = sign;
    int length = pred_length;
    for (int i = 0; i < length - 1; i++) {
        if (values[i] == values[i+1]) {
            if (values[i] == 3) {
                values[i] = 0;
                for (int j = i; j < length - 2; j++) {
                    values[j] = values[j+2];
                }
                length -= 2;
                i--;
                continue;
            } else if (values[i] == 8) {
                int p = 0;
                if (this->gsnow.getMax() >= 1024) {
                    p = 2;
                } else if (this->gsnow.getMax() >= 256) {
                    p = 5;
                } else {
                    p = 20;
                }
                if (this->gsnow.CountGarbage() % 2 == 1) {
                    p = 50;
                }
                int tmp = rand() % 100;
                if (tmp < p) {
                    values[i] = 3;
                } else {
                    values[i] = 16;
                    bonus += values[i];
                }
                needbig[i] = 1;
            } else {
                values[i] = values[i] * 2;
                bonus += values[i];
                needbig[i] = 1;
            }
            for (int j = i+1; j < length - 1; j++) {
                values[j] = values[j+1];
            }
            length--;
        }
    }
     curlen = length;
     for (int i = length; i < 4; i++) {
         values[i] = 0;
     }
     int has1succ = hasNum(1, values);
     if (this->gsnow.lb.isExcited() && this->gsnow.lb.isLove()) {
         if (has1pred != has1succ && has1succ != 0 && values[has1succ-1] != 3) {
            values[has1succ-1] *= 2;
            needbig[has1succ-1] = 1;
            bonus += values[has1succ-1];
            this->gsnow.lb.addBreak();
         }
     }
     if (this->gsnow.lb.isBreak()) {
         if (has1succ > 0 && values[has1succ-1] >= 4) {
             values[has1succ-1] /= 2;
             needbig[has1succ-1] = 1;
             bonus -= values[has1succ-1]*2;
             this->gsnow.lb.subBreak();
         }
     }
}

bool Grids::setA2(int &x, int &y) {
    int* wecan = new int [16];
    int curlen = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->gsnow.grids[i][j].getValue() == 0) {
                wecan[curlen] = i*4+j;
                curlen++;
            }
        }
    }
    if (curlen == 0) return false;
    int index = rand() % curlen;
    int i = wecan[index] / 4;
    int j = wecan[index] % 4;
    x = i;
    y = j;
    int num = (rand() % 1000) + 1;
    int p = 0;
    if (this->gsnow.getMax() >= 1024) {
        p = 1;
    } else if (this->gsnow.getMax() >= 256) {
        p = 2;
    } else {
        p = 3;
    }
    if (this->gsnow.lb.isExcited()) {
        p = 0;
    }
    if (num <= 900 - p * 9) {
        this->gsnow.grids[i][j].setValue(2);
    } else if (num <= 900 + p) {
        this->gsnow.grids[i][j].setValue(1);
        gsnow.lb.setInit();
    } else {
        this->gsnow.grids[i][j].setValue(4);
    }

    delete []wecan;
    return true;
}

void Grids::reset() {
    this->gsnow.setZero();
    int tmp1 = rand()%16;
    int tmp2 = rand()%16;
    this->gsnow.grids[tmp1/4][tmp1%4].setValue(2);
    this->gsnow.grids[tmp2/4][tmp2%4].setValue(2);
    this->gspred.setAs(this->gsnow);
    this->backleft = 3;
}

bool Grids::gameisover() {
    return this->gsnow.gameisover();
}

bool Grids::gameiswin() {
    return this->gsnow.gameiswin(this->winnum);
}

void Grids::backtopred() {
    if (this->canbeback()) {
        int subscore = 0;
        if (this->backleft == 3) {
            subscore = 100;
        }
        if (this->backleft == 2) {
            subscore = 200;
        }
        if (this->backleft == 1) {
            subscore = 500;
        }
        this->gsnow.setAs(this->gspred);
        this->gsnow.addScore(-subscore);
        this->backleft--;       
    }
}


