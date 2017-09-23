#ifndef QRESET_H
#define QRESET_H

#include <QLabel>

class QReset : public QLabel
{
    Q_OBJECT
public:
    explicit QReset(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked();

public slots:

};

#endif // QRESET_H
