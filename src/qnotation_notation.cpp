#include "./qnotation_notation.h"
#include <QMetaType>

namespace QNotation {

Notation::Notation()
{

}

Notation::Notation(const Notation &value)
{
    this->from(value);
}

Notation::Notation(const QVariant &value)
{
    this->from(value);
}

const Notation &Notation::operator=(const Notation&notation)
{
    return this->from(notation);
}

const Notation &Notation::operator=(const QVariant&notation)
{
    return this->from(notation);
}

bool Notation::operator==(const Notation&value) const
{
    return this->equal(value);
}

bool Notation::operator==(const QVariant&value)const
{
    return this->equal(value);
}

QByteArray Notation::name() const
{
    return this->_name;
}

int Notation::classification() const
{
    return this->_classification;
}

QVariant Notation::value() const
{
    return this->_value;
}

QVariant Notation::toVariant() const
{
    return this->toHash();
}

QVariantHash Notation::toHash() const
{
    return {{QStringLiteral("n"), this->_name}, {QStringLiteral("v"), this->_value}, {QStringLiteral("c"), this->_classification}};
}

QVariantMap Notation::toMap() const
{
    return {{QStringLiteral("n"), this->_name}, {QStringLiteral("v"), this->_value}, {QStringLiteral("c"), this->_classification}};
}

const Notation &Notation::from(const Notation &value)
{
    this->_name = value.name();
    this->_value = value.value();
    this->_classification = value.classification();
    return*this;
}


const Notation &Notation::from(const QVariant &value)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    int typeId=value.typeId();
#else
    int typeId=value.type();
#endif
    switch (typeId) {
    case QMetaType::QByteArray:
    case QMetaType::QString:
    case QMetaType::QChar:
    case QMetaType::QBitArray:
        this->_name=value.toByteArray().toLower().trimmed();
        this->_value.clear();
        this->_classification=0;
        break;
    case QMetaType::QVariantHash:
    case QMetaType::QVariantMap:{
        auto vHash = value.toHash();
        if(vHash.isEmpty())
            break;
        this->_name = vHash.value(QStringLiteral("n")).toByteArray().trimmed().toLower();
        this->_value = vHash.value(QStringLiteral("v"));
        this->_classification=vHash.value(QStringLiteral("c")).toInt();
        break;
    }
    default:
        break;
    }
    return*this;
}

bool Notation::equal(const Notation &notation) const
{
    if(notation.name()!=this->name())
        return {};

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    int typeId=this->_notation.typeId();
#else
    int typeId=this->_value.type();
#endif
    switch (typeId) {
    case QMetaType::QByteArray:
    case QMetaType::QString:
    case QMetaType::QChar:
    case QMetaType::QBitArray:{
        auto vA=this->value().toByteArray().trimmed().toLower();
        auto vB=notation.value().toByteArray().trimmed().toLower();
        if(vA!=vB)
            return {};
        break;
    }
    case QMetaType::QVariantHash:
    case QMetaType::QVariantMap:
    {
        auto vHashA=this->toHash();
        auto vHashB=notation.toHash();
        QHashIterator<QString, QVariant> i(vHashA);
        while(i.hasNext()){
            i.next();
            if(!vHashB.contains(i.key()))
                return {};

            if(i.value()!=vHashB.value(i.key()))
                return {};
        }
        break;
    }
    default:
        break;
    }

    return true;
}

bool Notation::equal(const QVariant &value) const
{
    return this->equal(Notation(value));
}

bool Notation::isValid() const
{
    if(this->_name.trimmed().isEmpty())
        return false;

    return true;
}

const Notation &Notation::clear()
{
    this->_name.clear();
    this->_value.clear();
    this->_classification=0;
    return*this;
}

}
