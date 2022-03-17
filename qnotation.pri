INCLUDEPATH += $$PWD/includes

QTREFORCE_QNOTATION=true
DEFINES+=QTREFORCE_QNOTATION

HEADERS += $$PWD/includes/QNotation

include($$PWD/src/qnotation.pri)
