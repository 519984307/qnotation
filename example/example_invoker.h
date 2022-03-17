#pragma once

#include <QObject>
#include <QVariantHash>
#include <QVariantList>
#include <QString>
#include <QNotation>
#include <QNotation>
#include "./example_controller.h"
#include "./example_defines.h"

namespace NotationExample {

//!
//! \brief The InvokerResponse struct
//!
//! response classe
struct InvokerResponse
{
public:
    int statusCode=-1;
    QByteArray responseBody;
    explicit InvokerResponse(){
    }
    explicit InvokerResponse(const int statusCode, const QByteArray&responseBody){
        this->statusCode=statusCode;
        this->responseBody=responseBody;
    }

    QString toString()
    {
        return QStringLiteral("%1, body: %2").arg(this->statusCode).arg(QString::fromUtf8(this->responseBody));
    }

};

//!
//! \brief The Invoker class
//!
//! class demo to Invoke method
class Invoker : public QObject, public NotationsDefines
{
    Q_OBJECT
public:
    explicit Invoker(QObject *parent = nullptr)
        : QObject{parent}, NotationsDefines{parent}
    {
    }

    //!
    //! \brief invokeBasePath
    //! \param method
    //! \param basePath
    //! \param body
    //! \return
    //!
    //!
    //! fake invoke method for test of notations
    //!reference https://restfulapi.net/http-status-codes/
    InvokerResponse invokeBasePath(const QByteArray&method, const QByteArray&basePath, const QByteArray&body)
    {
        Q_UNUSED(body)
        Controller controller;
        QNotation::Util util(&controller);
        auto methodName=basePath.simplified().split('/').last();

        if(methodName.isEmpty())
            return InvokerResponse{400,""};//400 Bad Request

        if(!util.contains(methodName, BASEPATH(basePath)))
            return InvokerResponse{405,""};//405 Method Not Allowed

        if(!util.contains(methodName, method))
            return InvokerResponse{406,""};//406 Not Acceptable


        {//invoke implementation
            //....
            if(true/*sucess*/)
                return InvokerResponse{200,body};//200 OK
        }

        return InvokerResponse{500,body};//500 Internal Server Error
    }

};

} // namespace NotationExample
