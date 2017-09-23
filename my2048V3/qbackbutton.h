#ifndef QBACKBUTTON_H
#define QBACKBUTTON_H

#include <QWidget>
#include <QLabel>

class QBackbutton : public QLabel
{
    Q_OBJECT
public:
    explicit QBackbutton(QWidget *parent = 0);
    void setAsback(bool canbeback, int backnum);

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked();

public slots:

};

#endif // QBACKBUTTON_H
