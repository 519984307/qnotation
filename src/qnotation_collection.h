#pragma once

#include <QObject>
#include <QMetaMethod>
#include <QHash>
#include "./qnotation_global.h"
#include "./qnotation_notation.h"

namespace QNotation {

//!
//! \brief NotationCollection
//!
class Q_NOTATION_EXPORT Collection:public QHash<QByteArray, Notation>{
public:
    //!
    //! \brief NotationCollection
    //!
    explicit Collection();

    //!
    //! \brief NotationCollection
    //! \param collection
    //!
    explicit Collection(const QHash<QByteArray, Notation> &collection);

    //!
    //! \brief find
    //! \param value
    //! \return
    //!
    bool find(const QVariant &value, Notation &notationOut)const;

    //!
    //! \brief find
    //! \param value
    //! \return
    //!
    const Notation &find(const QVariant &value)const;

    //!
    //! \brief contains
    //! \param value
    //! \return
    //!
    bool contains(const QVariant &value) const;

    //!
    //! \brief containsClassification
    //! \param classification
    //! \return
    //!
    bool containsClassification(int classification)const;

};

}
