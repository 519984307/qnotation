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
    enum Classification { Information, Documentation, Audit, Security };

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
    virtual const NotationCollection &notation() const;

    //!
    //! \brief notation
    //! \param method
    //! \return
    //!
    virtual const NotationCollection &notation(const QMetaMethod &method) const;
    virtual const NotationCollection &notation(const QByteArray &methodName) const;

    //!
    //! \brief notationMethods
    //! \return
    //!
    virtual NotationCollection notationMethods() const;

private:
    void *p = nullptr;
};

} // namespace QNotation
