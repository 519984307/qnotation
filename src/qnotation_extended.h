#pragma once

#include "./qnotation_collection.h"
#include "./qnotation_global.h"
#include "./qnotation_util.h"
#include <QHash>
#include <QMetaMethod>
#include <QObject>

namespace QNotation {

//!
//! \brief The NotationExtended class
//!
//! Notation Util
class Q_NOTATION_EXPORT Extended
{
public:
    enum Classification { Information, Documentation, Audit, Security, Operation };

    //!
    //! \brief NotationExtended
    //! \param parent
    //!
    explicit Extended(QObject *parent = nullptr);
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
    virtual Collection &notation() const;

    //!
    //! \brief notation
    //! \param method
    //! \return
    //!
    virtual Collection &notation(const QMetaMethod &method) const;
    virtual Collection &notation(const QByteArray &methodName) const;

    //!
    //! \brief notationMethods
    //! \return
    //!
    virtual Collection &notationMethods() const;

private:
    void *p = nullptr;
};

} // namespace QNotation
