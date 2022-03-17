#include "./qnotation_extended.h"
#include "./qnotation_util.h"

namespace QNotation {

#define dPvt()\
auto&p = *reinterpret_cast<NotationExtendedPvt*>(this->p)

class NotationExtendedPvt{
public:
    QObject*parent=nullptr;
    Util notationUtil;
    bool notationUtilLoaded=false;

    //!
    //! \brief NotationExtendedPvt
    //! \param parent
    //!
    explicit NotationExtendedPvt(QObject*parent)
    {
        this->parent=parent;
    }

    virtual ~NotationExtendedPvt()
    {
    }

    Util &nUtil()
    {
        if(!notationUtilLoaded){
            notationUtilLoaded=true;
            notationUtil.from(this->parent);
        }
        return this->notationUtil;
    }

};

Extended::Extended(QObject *parent)
{
    this->p=new NotationExtendedPvt(parent);
}

Extended::~Extended()
{
    dPvt();
    delete&p;
}

Util &Extended::notationUtil()
{
    dPvt();
    return p.nUtil();
}

QObject *Extended::parent()
{
    dPvt();
    return p.parent;
}

NotationCollection Extended::notation()const
{
    dPvt();
    return p.notationUtil.notation();
}

NotationCollection Extended::notation(const QMetaMethod &method)const
{
    dPvt();
    return p.notationUtil.notation(method);
}

NotationCollection Extended::notationMethods() const
{
    dPvt();
    return p.notationUtil.notationMethods();
}

}

