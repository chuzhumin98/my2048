#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    w = new Widget;//
    QPalette palette;
    palette.setColor(QPalette::Background,QColor(100,0,0));
    this->setPalette(palette);
}

Form::~Form()
{
    delete ui;
    delete w;//
}

void Form::on_pushButton_clicked()
{
    w->reset();
    w->grs->draw();
    w->show();
    this->hide();
}//

void Form::on_pushButton_2_clicked()
{
    w->show();
    this->hide();
}//
