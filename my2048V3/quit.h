#ifndef QUIT_H
#define QUIT_H

#include <QLabel>

class Quit : public QLabel
{
    Q_OBJECT
public:
    explicit Quit(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked();
public slots:

};


#endif // QUIT_H
