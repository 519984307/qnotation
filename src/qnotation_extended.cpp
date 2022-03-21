#include "./qnotation_extended.h"
#include "./qnotation_util.h"

namespace QNotation {

#define dPvt() auto &p = *reinterpret_cast<NotationExtendedPvt *>(this->p)

class NotationExtendedPvt
{
public:
    QObject *parent = nullptr;
    Util notationUtil;
    bool notationUtilLoaded = false;

    //!
    //! \brief NotationExtendedPvt
    //! \param parent
    //!
    explicit NotationExtendedPvt(QObject *parent) : notationUtil{parent}
    {
        if (parent == nullptr)
            qFatal("invalid notation parent");
        this->parent = parent;
    }

    virtual ~NotationExtendedPvt() {}
};

Extended::Extended(QObject *parent)
{
    this->p = new NotationExtendedPvt(parent);
}

Extended::~Extended()
{
    dPvt();
    delete &p;
}

Util &Extended::notationUtil()
{
    dPvt();
    return p.notationUtil;
}

QObject *Extended::parent()
{
    dPvt();
    return p.parent;
}

const NotationCollection &Extended::notation() const
{
    dPvt();
    return p.notationUtil.notation();
}

const NotationCollection &Extended::notation(const QMetaMethod &method) const
{
    dPvt();
    return p.notationUtil.notation(method);
}

const NotationCollection &Extended::notation(const QByteArray &methodName) const
{
    dPvt();
    return p.notationUtil.notation(methodName);
}

NotationCollection Extended::notationMethods() const
{
    dPvt();
    return p.notationUtil.notationMethods();
}

} // namespace QNotation
