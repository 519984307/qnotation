#include "./qnotation_collection.h"

namespace QNotation {

NotationCollection::NotationCollection()
    :
      QHash<QByteArray, Notation>{}
{

}

bool NotationCollection::find(const QVariant &value, Notation &notationOut)
{
    const auto &notation=this->find(value);
    if(notation.isValid()){
        notationOut=notation;
        return true;
    }

    notationOut.clear();
    return false;
}

const Notation &NotationCollection::find(const QVariant &value)
{
    static Notation __return(value);
    static Notation notationIn(value);
    if(!notationIn.isValid())
        return __return;

    QHashIterator<QByteArray, Notation> i(*this);
    while(i.hasNext()){
        i.next();
        auto &notation=i.value();
        if(notation==notationIn)
            return notation;
    }
    return __return;
}

bool NotationCollection::contains(const QVariant &value)const
{
    static Notation __return(value);
    static Notation notationIn(value);
    if(!notationIn.isValid())
        return {};

    QHashIterator<QByteArray, Notation> i(*this);
    while(i.hasNext()){
        i.next();
        auto &notation=i.value();
        if(notation.name()==notationIn.name())
            return true;
    }
    return {};
}

bool NotationCollection::containsClassification(int classification) const
{
    QHashIterator<QByteArray, Notation> i(*this);
    while(i.hasNext()){
        i.next();
        const auto &notation=i.value();
        if(notation.classification()==classification)
            return true;
    }
    return {};
}

}
