QT += testlib

CONFIG += testcase
CONFIG += console
CONFIG += silent
CONFIG -= debug_and_release
QT -= gui

TEMPLATE = app
TARGET = QNotationTest

INCLUDEPATH+=$$PWD/../src


QNOTATION_TEST_MODE=true
QMAKE_CXXFLAGS += -DQNOTATION_TEST_MODE=\\\"$$QNOTATION_TEST_MODE\\\"

LIBS += -lgmock
LIBS += -lgtest

include($$PWD/test/qnotation-test.pri)

