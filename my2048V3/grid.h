#ifndef GRID_H
#define GRID_H
#include <QLabel>
#include <QThread>
#include <waitthread.h>

class Grid: public QLabel
{
    Q_OBJECT
public:
    explicit Grid(QWidget *parent = 0);

    void setValue(int va) {
        value = va;
    }

    int getValue() {
        return value;
    }

    void mulValue() { value *= 2; }
    void setLabel();
    void setLoveorBreak(bool isLove, int num);

    void setAs(const Grid &g);
    void setLabelsmall(int num);
    int getPointSize(int num);

private:
    int value;

signals:

public slots:
    void startThreadtoSmall() {
        WaitThread* waitthread = new WaitThread(4, 50);
        connect(waitthread, SIGNAL(finished()), waitthread, SLOT(deleteLater()));
        connect(waitthread, SIGNAL(ready(int)), this, SLOT(setLabelSmallfromThread(int)));
        waitthread->start();
    }
    void startThreadtoBig() {
        WaitThread* waitthread = new WaitThread(4, 50);
        connect(waitthread, SIGNAL(finished()), waitthread, SLOT(deleteLater()));
        connect(waitthread, SIGNAL(ready(int)), this, SLOT(setLabelBigfromThread(int)));
        waitthread->start();

    }
    void setLabelSmallfromThread(int num) {
        int size = this->getPointSize(this->value);
        this->setFixedHeight(40+10*(num+1));
        this->setFixedWidth(88+23*(num+1));
        QFont ft;
        ft.setPointSize(size*(num+1)/4);
        ft.setBold(true);
        this->setFont(ft);
    }
    void setLabelBigfromThread(int num) {
        int size = this->getPointSize(this->value);
        this->setFixedHeight(95-num*5);
        this->setFixedWidth(210-10*num);
        QFont ft;
        ft.setPointSize(size);
        ft.setBold(true);
        this->setFont(ft);
    }

};

#endif // GRID_H
