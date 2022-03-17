#pragma once

//#include <QObject>
//#include <QVariantHash>
//#include <QVariantList>
//#include <QString>
#include <QNotation>

namespace NotationExample
{

//!
//! \brief The NotationsExtended class
//!
class NotationsDefines:public QNotation::Extended
{
    enum Classification{
        Operation
    };
public:

    explicit NotationsDefines(QObject*parent):QNotation::Extended(parent){
    }

    //!
    //! \brief GET
    //! \param parent
    //!
    Q_NOTATION_DECLARE(GET, Operation);

    //!
    //! \brief POST
    //! \param parent
    //!
    Q_NOTATION_DECLARE(POST, Operation);

    //!
    //! \brief PUT
    //! \param parent
    //!
    Q_NOTATION_DECLARE(PUT, Operation);

    //!
    //! \brief basePath
    //! \param path
    //! \return
    //!
    Q_NOTATION_DECLARE_FUNC(BASEPATH, Operation);
};

}
