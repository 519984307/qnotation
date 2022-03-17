#pragma once

#include <QObject>
#include <QMetaMethod>
#include <QHash>
#include "./qnotation_global.h"
#include "./qnotation_collection.h"
#include "./qnotation_util.h"

namespace QNotation {

//!
//! \brief The NotationExtended class
//!
//! Notation Util
class Q_NOTATION_EXPORT Extended
{
public:

    enum Classification{
        Information,
        Documentation,
        Audit,
        Security
    };

    //!
    //! \brief NotationExtended
    //! \param parent
    //!
    Q_INVOKABLE explicit Extended(QObject *parent = nullptr);
    virtual ~Extended();

    //!
    //! \brief util
    //! \return
    //!
    virtual QNotation::Util &notationUtil();

    //!
    //! \brief parent
    //! \return
    //!
    virtual QObject *parent();

    //!
    //! \brief notation
    //!
    virtual NotationCollection notation() const;

    //!
    //! \brief notation
    //! \param method
    //! \return
    //!
    virtual NotationCollection notation(const QMetaMethod &method) const;

    //!
    //! \brief notationMethods
    //! \return
    //!
    virtual NotationCollection notationMethods()const;
private:
    void*p=nullptr;
};

}
