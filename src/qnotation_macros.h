#pragma once

#include <QVariantHash>

#define Q_NOTATION_UTIL auto &nUtil=this->notationUtil()

#define Q_NOTATION(notationReference, notations)\
public:\
    Q_INVOKABLE QVariantList ___notation_declare_##notationReference()\
    {\
        static auto __return=QVariantList(notations);\
        return __return;\
    }

#define Q_NOTATION_COMPOSE(NAME, CLASSIFICATION, VALUE)\
QVariantHash{{QStringLiteral("n"), QStringLiteral(#NAME)}, {QStringLiteral("c"), CLASSIFICATION}, {QStringLiteral("v"), VALUE}}

#define Q_NOTATION_DECLARE_VALUE(NAME, CLASSIFICATION, VALUE) const QVariantHash NAME = Q_NOTATION_COMPOSE(NAME, CLASSIFICATION, VALUE);

#define Q_NOTATION_DECLARE(NAME, CLASSIFICATION) Q_NOTATION_DECLARE_VALUE(NAME, CLASSIFICATION, true);

#define Q_NOTATION_DECLARE_FUNC(NAME, CLASSIFICATION)\
static const QVariantHash NAME(const QVariant &value)\
{\
    return Q_NOTATION_COMPOSE(NAME, CLASSIFICATION, value);\
}
