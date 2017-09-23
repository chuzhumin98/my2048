#include "grid.h"
#include <QGraphicsDropShadowEffect>
#include <QTime>
#include <QCoreApplication>

Grid::Grid(QWidget *parent) :
    QLabel(parent)
{
    this->setFixedHeight(80);
    this->setFixedWidth(180);
    value = 0;
}

void Grid::setLabelsmall(int num) {
    setLabel();
    int size = this->getPointSize(num);
    for (int i = 1; i < 5; i++) {
        QTime t;
        t.start();
        this->setFixedHeight(20*i);
        this->setFixedWidth(45*i);
        QFont ft;
        ft.setPointSize(size*i/4);
        this->setFont(ft);
        if (i == 4) return;
        while(t.elapsed() < 15) {
            QCoreApplication::processEvents();
        }
    }
}

int Grid::getPointSize(int num) {
    switch (num) {
    case 0:
        return 30;
    case 1:
        return 30;
    case 2:
        return 30;
    case 3:
        return 30;
    case 4:
        return 30;
    case 8:
        return 30;
    case 16:
        return 30;
    case 32:
        return 20;
    case 64:
        return 20;
    case 128:
        return 20;
    case 256:
        return 30;
    case 512:
        return 20;
    case 1024:
        return 30;
    case 2048:
        return 30;
    case 4096:
        return 25;
    case 8192:
        return 25;
    case 16384:
        return 30;
    case 32768:
        return 30;
    case 65536:
        return 20;
    default:
        return 30;
    }
}

void Grid::setLabel() {
    this->setAutoFillBackground(true);
    setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(30);
    ft.setBold(true);
    this->setFrameShape(QFrame::Box);
    switch (value) {
    case 0: {
        this->setText("");
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(204,192,179));
        this->setPalette(pal);
        break;
    }
    case 1: {
        this->setText("123");
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(255, 0, 255));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, Qt::white);
        this->setPalette(pal);
        break;
    }
    case 2: {
        this->setText("Coffee");
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(238,228,218));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(119,110,101));
        this->setPalette(pal);
        break;
    }
    case 3: {
        this->setText("Garbage");
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, Qt::black);
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, Qt::white);
        this->setPalette(pal);
        break;
    }
    case 4: {
        this->setText("Panini");
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,224,200));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(119,110,101));
        this->setPalette(pal);
        break;
    }
    case 8: {
        this->setText("Idea");
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(242,177,121));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255,255,255));
        this->setPalette(pal);
        break;
    }
    case 16: {
        this->setText("Code");
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(245, 150, 100));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 32: {
        this->setText("Deep\nLearning");
        ft.setPointSize(20);
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(245,125,95));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 64: {
        this->setText("See\nSupervisor");
        ft.setPointSize(20);
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(245,95,60));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 128: {
        this->setText("Experiment");
        ft.setPointSize(20);
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,207,114));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 256: {
        this->setText("Paper");
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(20);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 512: {
        this->setText("Conference");
        ft.setPointSize(20);
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(30);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 1024: {
        this->setText("Viva");
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(40);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 2048: {
        this->setText("PhD");
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(50);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 4096: {
        this->setText("Postdoc");
        ft.setPointSize(25);
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(50);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 8192: {
        this->setText("Lecturer");
        ft.setPointSize(25);
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(50);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 16384: {
        this->setText("Reader");
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(50);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 32768: {
        this->setText("Prof.");
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(50);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    case 65536: {
        this->setText("Academician");
        ft.setPointSize(20);
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(50);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(237,204,97));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
        this->setPalette(pal);
        break;
    }
    default: {
        this->setGraphicsEffect(NULL);
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(238,228,218));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(119,110,101));
        this->setPalette(pal);
        break;
    }
    }
    ft.setPointSize(this->getPointSize(value));
    this->setFont(ft);
}

void Grid::setAs(const Grid &g) {
    value = g.value;
}

void Grid::setLoveorBreak(bool isLove, int num) {
    this->setAutoFillBackground(true);
    setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(30);
    ft.setBold(true);
    this->setFrameShape(QFrame::Box);
    this->setFixedHeight(80);
    this->setFixedWidth(180);
    this->setGraphicsEffect(NULL);
    QPalette pal;
    pal.setColor(QPalette::Window, QColor(255, 0, 255));
    this->setPalette(pal);
    pal.setColor(QPalette::WindowText, Qt::white);
    this->setPalette(pal);
    this->setFont(ft);
    if (isLove) {
        this->setText("Love " + QString::number(num));
    } else {
        this->setText("Break " + QString::number(num));
    }
}
