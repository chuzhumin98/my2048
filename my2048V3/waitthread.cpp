#include "waitthread.h"

WaitThread::WaitThread(QObject *parent) :
    QThread(parent)
{
}

void WaitThread::run() {
    if (times == -1) {
        while (true) {
            emit this->ready(0);
            msleep(this->interval);

        }
    } else {
        for (int i = 0; i < times; i++) {
            emit this->ready(i);
            msleep(this->interval);

        }
    }
}
