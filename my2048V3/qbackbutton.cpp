#include "qbackbutton.h"

QBackbutton::QBackbutton(QWidget *parent) :
    QLabel(parent)
{
    this->setText("Back");
    this->setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(30);
    ft.setBold(true);
    this->setFont(ft);
    this->setFixedHeight(80);
    this->setFixedWidth(210);
    this->setAutoFillBackground(true);
    this->setGraphicsEffect(NULL);
    QPalette pal;
    pal.setColor(QPalette::Window, QColor(143,122,102));
    this->setPalette(pal);
    pal.setColor(QPalette::WindowText, Qt::white);
    this->setPalette(pal);
}

void QBackbutton::mousePressEvent(QMouseEvent *event) {
    emit clicked();
}

void QBackbutton::setAsback(bool canbeback, int backnum) {
    this->setText("Back " + QString::number(backnum));
    if (canbeback) {
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(143,122,102));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, Qt::white);
        this->setPalette(pal);
    } else {
        QPalette pal;
        pal.setColor(QPalette::Window, QColor(143,122,102));
        this->setPalette(pal);
        pal.setColor(QPalette::WindowText, QColor(200,180,160));
        this->setPalette(pal);
    }
}
