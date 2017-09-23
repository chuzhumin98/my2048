#ifndef WAITTHREAD_H
#define WAITTHREAD_H

#include <QObject>
#include <QThread>

class WaitThread : public QThread
{
    Q_OBJECT
public:
    explicit WaitThread(QObject *parent = 0);
    WaitThread(int time, int inte): times(time), interval(inte) {}

protected:
    void run();

private:
    int times; // the times to transmit signal, -1 for infintity
    int interval; // the interval between each signal

signals:
    void ready(int index); // index: 0~times-1

public slots:


};

#endif // WAITTHREAD_H
