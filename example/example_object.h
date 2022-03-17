#pragma once

#include <QNotation>
#include "./example_defines.h"

namespace NotationExample {

class Object : public QNotation::Object<QObject>, public Private::NotationsDefines {
    Q_OBJECT
public:
    Q_INVOKABLE explicit Object(QObject*parent=nullptr)
        :
          QNotation::Object<QObject>{parent}
    {
    }
};

}

