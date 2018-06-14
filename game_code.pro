#-------------------------------------------------
#
# Project created by QtCreator 2018-05-17T18:03:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_code
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    icon.cpp \
    rpgobj.cpp \
    player.cpp \
    male_player.cpp \
    female_player.cpp \
    final_player.cpp \
    world1.cpp \
    world2.cpp \
    world3.cpp \
    fairy.cpp \
    skill.cpp \
    monster.cpp \
    property.cpp

HEADERS  += mainwindow.h \
    icon.h \
    rpgobj.h \
    player.h \
    male_player.h \
    female_player.h \
    final_player.h \
    world1.h \
    world2.h \
    world3.h \
    fairy.h \
    skill.h \
    monster.h \
    property.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
