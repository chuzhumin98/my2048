#ifndef QGAMEOVER_H
#define QGAMEOVER_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "qreset.h"
#include "quit.h"

class QGameOver : public QWidget
{
    Q_OBJECT
public:
    explicit QGameOver(QWidget *parent = 0);

public:
    QLabel* gameover;
    QReset *reset;
    QVBoxLayout *mainLayout;
    QVBoxLayout *bottomLayout;
    Quit *quit;

signals:

public slots:

};

#endif // QGAMEOVER_H
