QT += dbus network

include(../common-install.pri)

TEMPLATE = app
TARGET = sensordataflow-test

CONFIG += testcase

HEADERS += dataflowtests.h
SOURCES += dataflowtests.cpp

INCLUDEPATH += ../../include \
    ../../chains \
    ../../core \
    ../../datatypes \
    ../../chains \
    ../../filters \
    ../../filters/coordinatealignfilter \
    ../../adaptors \
    ../..

QMAKE_LIBDIR_FLAGS += -L../../builddir/datatypes -L../../datatypes/ -lsensordatatypes
QMAKE_LIBDIR_FLAGS += -L../../builddir/core -L../../core/ -lsensorfw
QMAKE_RPATHDIR += /usr/lib/sensord
