#pragma once

#include <QObject>
#include <QVariantHash>
#include <QVariantList>
#include <QString>
#include <QNotation>

namespace Private
{

//!
//! \brief The NotationsExtended class
//!
class NotationsDefines
{
public:
    //!
    //! \brief GET
    //! \param parent
    //!
    Q_NOTATION_DECLARE(GET);

    //!
    //! \brief POST
    //! \param parent
    //!
    Q_NOTATION_DECLARE(POST);

    //!
    //! \brief PUT
    //! \param parent
    //!
    Q_NOTATION_DECLARE(PUT);

    //!
    //! \brief basePath
    //! \param path
    //! \return
    //!
    static const QVariantHash BASEPATH(const QVariant &path={})
    {
        return Q_NOTATION_MAKE(path);
    }
private:

};

}
