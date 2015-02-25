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
    psovectorunit.cpp \
    psounitdouble.cpp \
    pso.cpp \
    psosolution.cpp \
    psosolutiontemplate.cpp \
    randomc/mersenne.cpp \
    randomc/testirandomx.cpp \
    randomc/userintf.cpp

HEADERS += \
    psovectorunit.h \
    psounitdouble.h \
    pso.h \
    psosolution.h \
    psosolutiontemplate.h \
    randomc/randomc.h
