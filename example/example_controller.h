#pragma once

#include "./example_object.h"
#include "./example_defines.h"

namespace NotationExample {

class Controller : public Object {
    Q_OBJECT
    Q_NOTATION(Controller, {BASEPATH("/api")})
public:
    Q_INVOKABLE explicit Controller(QObject*parent=nullptr):Object(parent)
    {
    }

    Q_NOTATION(healtCheck, nl({GET, BASEPATH("/healtCheckV1")}))
    Q_INVOKABLE QVariant healtCheckV1(){
        return {};
    }

    Q_NOTATION(healtCheckV2, nl({GET, BASEPATH("/healtCheck")}))
    Q_INVOKABLE QVariant healtCheckV2(){
        return {};
    }

    Q_NOTATION(insert, {POST})
    Q_INVOKABLE QVariant insert(){
        return {};
    }

    Q_NOTATION(update, {PUT})
    Q_INVOKABLE QVariant update(){
        return {};
    }

};

}

