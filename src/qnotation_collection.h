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
    bool find(const QVariant &value, Notation &notationOut);
    const Notation &find(const QVariant &value);
    bool contains(const QVariant &value) const;
    bool containsClassification(int classification)const;
};

}
