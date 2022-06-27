#pragma once

#include "./qnotation_collection.h"
#include "./qnotation_global.h"
#include <QByteArray>
#include <QHash>
#include <QMetaMethod>
#include <QObject>

namespace QNotation {

//!
//! \brief The Util class
//!
//! Notation Util
class Q_NOTATION_EXPORT Util
{
public:
    //!
    //! \brief The Type enum
    //!
    enum Type { Class, Method };

    //!
    //! \brief Util
    //! \param parent
    //!
    explicit Util(QObject *parent = nullptr);
    virtual ~Util();

    //!
    //! \brief from
    //! \param object
    //! \return
    //!
    Util &from(QObject *object);

    //!
    //! \brief contains
    //! \param methodName
    //! \param notationName
    //! \return
    //!
    virtual bool contains(const QByteArray &methodName, const QVariant &vNotation) const;

    //!
    //! \brief notationsClass
    //! \param parent
    //! \return
    //!
    virtual QHash<Type, Collection> &notations() const;

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
