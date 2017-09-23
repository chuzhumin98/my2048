#include <QtGui/QApplication>
#include <QSound>
#include "widget.h"
#include "topscore.h"
#include "bgmusicthread.h"
#include "form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BgMusicThread bgt;
    bgt.startThread();
//    Widget w;
//    w.show();
    Form f;//
    f.show();//
    QObject::connect(f.w->gameover->quit, SIGNAL(clicked()), &a, SLOT(quit()));
    return a.exec();
}
