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
class Q_NOTATION_EXPORT NotationCollection:public QHash<QByteArray, Notation>{
public:
    //!
    //! \brief NotationCollection
    //!
    explicit NotationCollection();

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
