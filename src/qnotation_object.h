#pragma once

#include <QObject>
#include "./qnotation_global.h"
#include "./qnotation_extended.h"

namespace QNotation {

//!
//! \brief The ObjectNotation class
//!
template <class T=QObject>
class Object : public T, public Extended
{
public:

    //!
    //! \brief ObjectNotation
    //! \param parent
    //!
    Q_INVOKABLE explicit Object(QObject *parent = nullptr)
        :
          T{parent}, Extended{this}
    {
    }
};

}
