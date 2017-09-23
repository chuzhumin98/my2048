#include "lovebreak.h"

LoveBreak::LoveBreak(QObject *parent) :
    QObject(parent)
{
    this->breakleft = 0;
    this->loveleft = 0;
}

void LoveBreak::setAs(const LoveBreak &lb) {
    this->breakleft = lb.breakleft;
    this->loveleft = lb.loveleft;
}
