#ifndef LOVEBREAK_H
#define LOVEBREAK_H
#include "grid.h"

#include <QObject>

class LoveBreak : public QObject
{
    Q_OBJECT
public:
    explicit LoveBreak(QObject *parent = 0);

    void setInit() {
        loveleft = 6;
        breakleft = 0;
    }

    void setZero() {
        loveleft = 0;
        breakleft = 0;
    }

    bool isfinished() {
        if (loveleft <= 0 && breakleft <= 0) return true;
        return false;
    }

    bool isExcited() { return !isfinished(); }
    bool isLove() { return loveleft != 0; }
    bool isBreak() { return (breakleft != 0 && loveleft == 0); }

    void subLove() { loveleft--; }
    void addBreak() { breakleft++; }
    void subBreak() { breakleft--; }
    void setLove(int n) { loveleft = n; }
    void setBreak(int n) { breakleft = n; }
    void setAs(const LoveBreak &lb);
    int getLove() { return loveleft; }
    int getBreak() { return breakleft; }

private:
    int loveleft; // love status left step number
    int breakleft; // break status occurs after love

signals:

public slots:

};

#endif // LOVEBREAK_H
