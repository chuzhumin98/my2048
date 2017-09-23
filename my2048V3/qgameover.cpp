#include "qgameover.h"

QGameOver::QGameOver(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("GameOver");
    gameover = new QLabel;
    gameover->setText("Game is over!\nPlease back to reset.");
    gameover->setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(40);
    ft.setBold(true);
    gameover->setFont(ft);
    gameover->setFixedHeight(400);
    gameover->setFixedWidth(720);
    //gameover->setAutoFillBackground(true);
    gameover->setGraphicsEffect(NULL);
    QPalette pal;
    //pal.setColor(QPalette::Window, QColor(143,122,102));
    //this->setPalette(pal);
    pal.setColor(QPalette::WindowText, QColor(130,118,109));
    pal.setColor(QPalette::Window, QColor(0,0,0));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    reset = new QReset;
    reset->setText("Quit");

    quit = new Quit;


    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(gameover, 0, Qt::AlignCenter);
    bottomLayout = new QVBoxLayout;
    mainLayout->insertLayout(1,bottomLayout);
    bottomLayout->insertWidget(0,reset,0,Qt::AlignCenter);
    bottomLayout->insertWidget(1,quit,0,Qt::AlignCenter);


    this->setLayout(mainLayout);
}
