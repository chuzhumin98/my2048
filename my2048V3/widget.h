#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStyleOption>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QCloseEvent>

#include "grid.h"
#include "grids.h"
#include "qreset.h"
#include "qgameover.h"
#include "qbackbutton.h"
#include "topscore.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    Grids* grs;
    QGameOver *gameover;
    ~Widget();
    void setTitle();
    void setScore();
    void setGamewin();
    void refresh();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    Ui::Widget *ui;
    QLabel* title;
    QLabel* score;
    QLabel* gamewin;
    QBackbutton* backbutton;
    QReset* resets;
    QHBoxLayout *titleLayout;
    QHBoxLayout *titleLayout3;
    QVBoxLayout *mainLayout;
    TopScore top;

public slots:
    void reset() {
        top.add(this->grs->getScore());
        grs->reset();
        this->refresh();
        //this->resets->setText("OK");
    }
    void back() {
        grs->backtopred();
        this->refresh();
    }

};

#endif // WIDGET_H
