#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "widget.h"//

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Widget *w;
    explicit Form(QWidget *parent = 0);
    ~Form();

private:
    Ui::Form *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // FORM_H
