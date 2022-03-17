#pragma once

#include <QNotation>
#include "./example_defines.h"

namespace NotationExample {

class Object : public QObject, public NotationsDefines {
    Q_OBJECT
public:
    Q_INVOKABLE explicit Object(QObject*parent=nullptr)
        :
          QObject{parent},
          NotationsDefines{this}
    {
    }
};

}

