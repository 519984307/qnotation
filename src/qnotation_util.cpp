#include "./qnotation_util.h"

namespace QNotation {

#define dPvt()\
auto&p = *reinterpret_cast<UtilPvt*>(this->p)


class UtilPvt{
public:
    Util*util=nullptr;
    QObject*parent=nullptr;
    QHash<Util::Type, NotationCollection> notations;
    QHash<QByteArray, NotationCollection> notationsMethods;

    //!
    //! \brief UtilPvt
    //! \param parent
    //!
    explicit UtilPvt(Util*util, QObject*parent)
    {
        this->util=util;
        this->parent=parent;
        this->buildNotations();
    }

    virtual ~UtilPvt()
    {
    }

    //!
    //! \brief notationMaker
    //! \param notations
    //! \return
    //!
    NotationCollection notationMaker(const QVariant &notations)const
    {
        NotationCollection __return;
        QVariantList vList;

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
        int typeId=notations.typeId();
#else
        int typeId=notations.type();
#endif
        switch (typeId) {
        case QMetaType::QVariantList:
        case QMetaType::QStringList:
        case QMetaType::QVariantHash:
        case QMetaType::QVariantMap:
            vList=notations.toList();
            break;
        default:
            vList<<notations;
        }

        for(auto&v:vList){
            auto vHash=v.toHash();

            if(vHash.isEmpty())
                continue;

            QHashIterator<QString, QVariant> i(vHash);
            while(i.hasNext()){
                i.next();
                auto v=i.value().toHash();
                if(v.isEmpty())
                    continue;

                auto k=i.key().toUtf8();
                __return.insert(k, Notation(v));
            }
        }
        return __return;
    }

    //!
    //! \brief buildNotations
    //! \return
    //!
    void buildNotations()
    {
        if(this->parent==nullptr)//check Object to extract notations
            return;

        static const auto ___notation_declare_=QByteArrayLiteral("___notation_declare_");//start name of QNotation methods

        auto makeObject=this->parent;
        auto metaObject=makeObject->metaObject();
        //class name
        auto notationRefereceClass=QByteArray(metaObject->className()).split(':').last().toLower();

        NotationCollection vNotationsClass;
        NotationCollection vNotationsMethod;

        for (auto i = 0; i < metaObject->methodCount(); ++i) {
            auto method = metaObject->method(i);

            if(method.methodType()!=method.Method)//ignore no method
                continue;

            if(method.parameterCount()>0)//ignore method with parameters
                continue;

            const auto methodName = method.name().toLower();
            if(!methodName.startsWith(___notation_declare_))//check method forma declaration for QNotation
                continue;

            const auto notationRefereceMethod=methodName.split('_').last();//extract method name at QNotation declaration

            NotationCollection vNotationsMethodExclusive;//exclusive list for methods
            QVariant returnVariant;//variable to invoke response

            //invoke QNotation method
            if(method.invoke(makeObject, Qt::DirectConnection, Q_ARG(QVariant, returnVariant))){

                auto notationList=notationMaker(returnVariant);

                if(notationList.isEmpty())//skip to empty values
                    continue;

                if(notationRefereceMethod==notationRefereceClass){//check notation is the scope class
                    for(auto&notation:notationList)
                        vNotationsClass.insert(notation.name(), notation);
                    continue;
                }

                {//notations at scope methods
                    for(auto&notation:notationList){
                        vNotationsMethod.insert(notation.name(), notation);
                        vNotationsMethodExclusive.insert(notation.name(), notation);
                    }
                    this->notationsMethods.insert(notationRefereceMethod, vNotationsMethodExclusive);
                }
            }
        }
        //persist notation class and methods
        this->notations={{Util::Class, vNotationsClass}, {Util::Method, vNotationsMethod}};
    }
};


Util::Util(QObject *parent)
{
    this->p=new UtilPvt(this, parent);
}

Util::~Util()
{
    dPvt();
    delete&p;
}

Util &Util::from(QObject *object)
{
    dPvt();
    p.parent=object;
    p.buildNotations();
    return*this;
}

bool Util::contains(const QByteArray &methodName, const QVariant &vNotation)const
{
    dPvt();
    NotationCollection &notations=p.notationsMethods[methodName.toLower()];
    const auto&notation=notations.find(vNotation);
    return notation.isValid();
}

QHash<Util::Type, NotationCollection> &Util::notations()const
{
    dPvt();
    return p.notations;
}

const NotationCollection &Util::notation()const
{
    dPvt();
    return p.notations[Util::Class];
}

const NotationCollection Util::notation(const QMetaMethod &method) const
{
    dPvt();
    return p.notationsMethods[method.name()];
}

const NotationCollection &Util::notationMethods() const
{
    dPvt();
    return p.notations[Util::Method];
}

}
