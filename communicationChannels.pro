#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T10:07:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = communicationChannels
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    imageanalyzer.cpp \
    communicationchannel.cpp

HEADERS  += mainwindow.h \
    about.h \
    imageanalyzer.h \
    communicationchannel.h

FORMS    += mainwindow.ui \
    about.ui
