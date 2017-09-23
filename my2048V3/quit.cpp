#include "quit.h"

Quit::Quit(QWidget *parent) :
    QLabel(parent)
{
    this->setText("Close");
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

void Quit::mousePressEvent(QMouseEvent *event) {
    //this->setText("123");
    emit clicked();
}

