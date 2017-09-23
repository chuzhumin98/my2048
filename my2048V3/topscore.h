#ifndef TOPSCORE_H
#define TOPSCORE_H
#include <QFile>
#include <QTextStream>

class TopScore
{
public:
    TopScore();
    int getTop() { return topscore; }
    void setTop(int ts) { topscore = ts; }
    void add(int sc);

private:
    int topscore;
};

#endif // TOPSCORE_H
