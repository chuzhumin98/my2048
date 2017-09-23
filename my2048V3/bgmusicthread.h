#ifndef BGMUSICTHREAD_H
#define BGMUSICTHREAD_H

#include <QObject>
#include <QThread>
#include <QSound>
//#include <phonon/Phonon>
#include "waitthread.h"

class BgMusicThread : public QObject
{
    Q_OBJECT
public:
    explicit BgMusicThread(QObject *parent = 0);


signals:

public slots:

    void startThread() {
        WaitThread* waitthread = new WaitThread(-1, 230*1000);
        connect(waitthread, SIGNAL(finished()), waitthread, SLOT(deleteLater()));
        connect(waitthread, SIGNAL(ready(int)), this, SLOT(replayMusic(int)));
        waitthread->start();

    }
    void replayMusic(int num) {
        QSound bg("bg5.wav");
        bg.play();
        /*Phonon::MediaObject *media = new Phonon::MediaObject;
        Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(this);
        media->setCurrentSource(Phonon::MediaSource("bg1.mp3"));
        Phonon::createPath(media, audioOutput);
        media->play(); */
    }
};

#endif // BGMUSICTHREAD_H
