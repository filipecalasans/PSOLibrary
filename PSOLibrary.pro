#-------------------------------------------------
#
# Project created by QtCreator 2015-02-21T23:56:48
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = PSOLibrary
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    pso.cpp \
    randomc/mersenne.cpp \

HEADERS += \
    pso.h \
    randomc/randomc.h
