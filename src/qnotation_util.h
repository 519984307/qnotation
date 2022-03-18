#pragma once

#include <QObject>
#include <QMetaMethod>
#include <QHash>
#include <QByteArray>
#include "./qnotation_global.h"
#include "./qnotation_collection.h"

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
    enum Type{
        Class, Method
    };

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
    virtual bool contains(const QByteArray&methodName, const QVariant &vNotation) const;

    //!
    //! \brief notationsClass
    //! \param parent
    //! \return
    //!
    virtual QHash<Type, NotationCollection> &notations()const;

    //!
    //! \brief notation
    //!
    virtual const NotationCollection &notation() const;

    //!
    //! \brief notation
    //! \param method
    //! \return
    //!
    virtual const NotationCollection &notation(const QMetaMethod &method)const;
    virtual const NotationCollection &notation(const QByteArray &methodName)const;

    //!
    //! \brief notationMethods
    //! \return
    //!
    virtual const NotationCollection &notationMethods()const;
private:
    void*p=nullptr;
};

}
