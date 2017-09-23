#-------------------------------------------------
#
# Project created by QtCreator 2017-09-09T23:03:51
#
#-------------------------------------------------

QT       += core gui
QT       += phonon

TARGET = my2048V3
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    topscore.cpp \
    savegame.cpp \
    qreset.cpp \
    qgameover.cpp \
    qbackbutton.cpp \
    gridsstate.cpp \
    grids.cpp \
    grid.cpp \
    bgmusicthread.cpp \
    lovebreak.cpp \
    waitthread.cpp \
    quit.cpp \
    form.cpp

HEADERS  += widget.h \
    topscore.h \
    savegame.h \
    qreset.h \
    qgameover.h \
    qbackbutton.h \
    gridsstate.h \
    grids.h \
    grid.h \
    bgmusicthread.h \
    lovebreak.h \
    waitthread.h \
    quit.h \
    form.h

FORMS    += widget.ui \
    form.ui

RESOURCES +=
