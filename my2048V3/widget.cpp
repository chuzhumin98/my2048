#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include "savegame.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Window, QColor(224,212,199));
    this->setPalette(pal);
    this->setWindowTitle("my2048");
    mainLayout = new QVBoxLayout();
    titleLayout = new QHBoxLayout();
    titleLayout3 = new QHBoxLayout();
    gameover = new QGameOver;
    resets = new QReset;
    backbutton = new QBackbutton;
    setTitle();
    setScore();
    setGamewin();
    titleLayout->insertWidget(1, title, 0, Qt::AlignCenter);
    titleLayout->insertWidget(0, score, 0, Qt::AlignLeft);
    titleLayout->insertWidget(2, resets, 0, Qt::AlignRight);
    titleLayout3->insertWidget(0, gamewin, 0, Qt::AlignLeft);
    titleLayout3->insertWidget(1, backbutton, 0, Qt::AlignRight);
    grs = new Grids;
    grs->draw();

    mainLayout->insertLayout(2, grs->boardLayout);
    mainLayout->insertLayout(0, titleLayout);
    mainLayout->insertLayout(1, this->titleLayout3);
    this->setLayout(mainLayout);
    this->refresh();

    connect(resets, SIGNAL(clicked()), this, SLOT(reset()));
    connect(this->backbutton, SIGNAL(clicked()), this, SLOT(back()));
    connect(gameover->reset, SIGNAL(clicked()), this, SLOT(reset()));

}


Widget::~Widget()
{
    delete this->grs;
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Up:
        this->grs->move(UP);
        this->refresh();
        break;
    case Qt::Key_Left:
        this->grs->move(LEFT);
        this->refresh();
        break;
    case Qt::Key_Right:
        this->grs->move(RIGHT);
        this->refresh();
        break;
    case Qt::Key_Down:
        this->grs->move(DOWN);
        this->refresh();
        break;
    }
}

void Widget::mousePressEvent(QMouseEvent *event) {

}

void Widget::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("close"),
            QString(tr("Do you want to save this game?")),
            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if (button == QMessageBox::Yes) {
        SaveGame sg(this->grs->getgsnow());
        sg.saveAsthis();
        event->accept();  // do not save this game, new a game
    } else if (button == QMessageBox::No) {
        this->grs->reset();
        SaveGame sg(this->grs->getgsnow());
        sg.saveAsthis();
        event->accept();  // save this game
    } else if (button == QMessageBox::Cancel) {
        event->ignore(); // do not close this game
    }

}

void Widget::setTitle() {
    title = new QLabel;
    title->setText("2048");
    title->setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(50);
    ft.setBold(true);
    title->setFont(ft);
    title->setFixedHeight(100);
    title->setFixedWidth(180);
}

void Widget::setScore() {
    score = new QLabel;
    //score->setText("2048");
    score->setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(20);
    //ft.setBold(true);
    score->setFont(ft);
    score->setFixedHeight(100);
    score->setFixedWidth(180);
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::blue);
    score->setPalette(pal);
}

void Widget::setGamewin() {
    this->gamewin = new QLabel;
    gamewin->setText("You win! Keep playing to increase your score.");
    gamewin->setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(15);
    //ft.setBold(true);
    gamewin->setFont(ft);
    gamewin->setFixedHeight(60);
    gamewin->setFixedWidth(500);
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::red);
    gamewin->setPalette(pal);
}


void Widget::refresh() {
    this->grs->draw();
    this->top.add(this->grs->getScore());
    if (this->grs->gameisover()) {
        this->gameover->show();
    } else {
        this->gameover->hide();
    }
    if (this->grs->gameiswin()) {
        this->gamewin->show();
    } else {
        this->gamewin->hide();
    }
    this->backbutton->setAsback(this->grs->canbeback(), this->grs->getBackleft());
    this->score->setText("score:"+QString::number(this->grs->getScore())+"\ntop:"+QString::number(this->top.getTop()));
 //   this->gameover->show();
}
