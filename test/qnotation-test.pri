include($$PWD/../qnotation.pri)

#INCLUDEPATH+=$$PWD

CONFIG += console
CONFIG -= debug_and_release
CONFIG += testcase
LIBS += -L/usr/local/lib -lgmock
LIBS += -L/usr/local/lib -lgtest

QNOTATION_TEST_MODE=true
QMAKE_CXXFLAGS += -DQNOTATION_TEST_MODE=\\\"$$QNOTATION_TEST_MODE\\\"

HEADERS += \
    $$PWD/qnotation_test.h \
    $$PWD/qnotation_test_functional.h \
    $$PWD/qnotation_test_unit.h

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/qnotation_unit_test.cpp
