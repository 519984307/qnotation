


>## QNotation
>**Set of classes and macros for use of notation to work class and methods in framework C++/Qt.**
>Based on class/structs ***Qt*** and ***c++*** , using ***QHash, QVariantHash and QVariantList*** create colletions of notations for objects.
> 1. Decreases implementations in object inheritance.
> 2. Simplifies understanding of use.
> 3. Increase customization possibilities

## Working architecture
>## Support
> Qt5, Qt6

## Prerequisits
>```bash
> mkdir myproject;
> cd myproject;
> git clone git@github.com:flaviomarcio/qnotation.git;
>```
>Check example in qnotation/example/*


## CMake Build information

>```
>## initial CMake parameters 
>
>-GNinja
>-DCMAKE_BUILD_TYPE:STRING=Debug
>-DCMAKE_PROJECT_INCLUDE_BEFORE:PATH=%{IDE:ResourcePath}/package-manager/auto-setup.cmake
>-DQT_QMAKE_EXECUTABLE:STRING=%{Qt:qmakeExecutable}
>-DCMAKE_PREFIX_PATH:STRING=%{Qt:QT_INSTALL_PREFIX}
>-DCMAKE_C_COMPILER:STRING=%{Compiler:Executable:C}
>-DCMAKE_CXX_COMPILER:STRING=%{Compiler:Executable:Cxx}
>-DCMAKE_INSTALL_PREFIX=~/build/myproject/install/release
>```

>```bash
> cd qnotation
> mkdir build;
> cd build;
> cmake ..
> make;
> make install;
>```

## QMake Build information

>```bash
> cd qnotation
> qmake qnotation.pro
> make;
> make install;
> ls -l;
>```

## Configure QMake project

>```c++
>CONFIG += c++17
>CONFIG += console
>CONFIG += silent
>CONFIG -= debug_and_release
>QT += gui core widgets
>
>TEMPLATE = app
>TARGET = demo
>
>include($$PWD/../../../qnotation/qnotation.pri)
>```

## Notation implementation
>Using source of example of repository
>## Notation customize
>Based on class/structs ***Qt*** and ***c++*** , using ***QHash, QVariantHash and QVariantList*** create colletions of notations for objects.
>```c++
>#include <QNotation>
>
>//!
>//! \brief The NotationsExtended class
>//!
>class NotationsDefines:public QNotation::Extended
>{
>    enum Classification{
>        Operation
>    };
>public:
>
>    explicit NotationsDefines(QObject*parent):QNotation::Extended(parent){
>    }
>
>    //!
>    //! \brief GET
>    //! \param parent
>    //!
>    Q_NOTATION_DECLARE(GET, Operation);
>
>    //!
>    //! \brief POST
>    //! \param parent
>    //!
>    Q_NOTATION_DECLARE(POST, Operation);
>
>    //!
>    //! \brief PUT
>    //! \param parent
>    //!
>    Q_NOTATION_DECLARE(PUT, Operation);
>
>    //!
>    //! \brief basePath
>    //! \param path
>    //! \return
>    //!
>    Q_NOTATION_DECLARE_FUNC(BASEPATH, Operation);
>};
>
>    qWarning()<<simpleObject.lr().resultByteArray();
>}
>```
>## Associate QNotation  with QObject
>Using inheritance we merge ***QObject*** and ****** and ***NotationsExtended***, being possible to use custom notations.
>```c++
>#include <QNotation>
>
>class Object : public QObject, public NotationsDefines {
>    Q_OBJECT
>public:
>    Q_INVOKABLE explicit Object(QObject*parent=nullptr)
>        :
>          QObject{parent},
>          NotationsDefines{this}
>    {
>    }
>};
>```
>## Using/Configuring notation in methods of object
>>The idea is to use MACRO to configure notation in methods
>>The pivote é macro ***Q_NOTATION*** for set method and notations values.
>>
>>Single Notation
>>>Example ***Q_NOTATION(Controller, {BASEPATH("/api")})*** .
>>>Example ***Q_NOTATION(Controller, nl{BASEPATH("/api")})*** .
>>>
>>Multple Notation
>>>Example ***Q_NOTATION(healtCheck, nl({GET, BASEPATH("/healtCheckV1")}))*** .
>```c++
>#include <QNotation>
>#include "./example_defines.h"
>
>class Controller : public Object {
>    Q_OBJECT
>    Q_NOTATION(Controller, {BASEPATH("/api")})
>public:
>    Q_INVOKABLE explicit Controller(QObject*parent=nullptr):Object(parent)
>    {
>    }
>
>    Q_NOTATION(healtCheck, nl({GET, BASEPATH("/healtCheckV1")}))
>    Q_INVOKABLE QVariant healtCheckV1(){
>        return {};
>    }
>
>    Q_NOTATION(healtCheckV2, nl({GET, BASEPATH("/healtCheck")}))
>    Q_INVOKABLE QVariant healtCheckV2(){
>        return {};
>    }
>
>    Q_NOTATION(insert, {POST})
>    Q_INVOKABLE QVariant insert(){
>        return {};
>    }
>
>    Q_NOTATION(update, {PUT})
>    Q_INVOKABLE QVariant update(){
>        return {};
>    }
>
>};
>```
>## Class for notation manipulation of object
>>## Method notation recovery
>>Strategy:
>> Recovery of method notation.
>> Use notation for behaviors.
>
>## Struct for response
>```c++
>#include <QNotation>
>
>//!
>//! \brief The InvokerResponse struct
>//!
>//! response classe
>struct InvokerResponse
>{
>public:
>    int statusCode=-1;
>    QByteArray responseBody;
>    explicit InvokerResponse(){
>    }
>    explicit InvokerResponse(const int statusCode, const QByteArray&responseBody){
>        this->statusCode=statusCode;
>        this->responseBody=responseBody;
>    }
>
>    QString toString()
>    {
>        return QStringLiteral("%1, body: %2").arg(this->statusCode).arg(QString::fromUtf8(this->responseBody));
>    }
>};
>```
>## Creating class to use notation
>The idea is to create a fake ***REST Server***, we implemented the operation ***GET, POST, PUT***
>```c++
>//!
>//! \brief The Invoker class
>//!
>//! class demo to Invoke method
>class Invoker : public QObject, public NotationsDefines
>{
>    Q_OBJECT
>public:
>    explicit Invoker(QObject *parent = nullptr)
>        : QObject{parent}, NotationsDefines{parent}
>    {
>    }
>
>    //!
>    //! \brief invokeBasePath
>    //! \param method
>    //! \param basePath
>    //! \param body
>    //! \return
>    //!
>    //!
>    //! fake invoke method for test of notations
>    //!reference https://restfulapi.net/http-status-codes/
>    InvokerResponse invokeBasePath(const QByteArray&method, const QByteArray&basePath, const QByteArray&body)
>    {
>        Q_UNUSED(body)
>        Controller controller;
>        QNotation::Util util(&controller);
>        auto methodName=basePath.simplified().split('/').last();
>
>        if(methodName.isEmpty())
>            return InvokerResponse{400,""};//400 Bad Request
>
>        if(!util.contains(methodName, BASEPATH(basePath)))
>            return InvokerResponse{405,""};//405 Method Not Allowed
>
>        if(!util.contains(methodName, method))
>            return InvokerResponse{406,""};//406 Not Acceptable
>
>        {//invoke implementation
>            //....
>            if(true/*sucess*/)
>                return InvokerResponse{200,body};//200 OK
>        }
>        return InvokerResponse{500,body};//500 Internal Server Error
>    }
>};
>```
>## Using class implemented Invoker class
>The call occurs executing method with parameters compatible with ***REST***
>```c++
>#include <QNotation>
>#include <QCoreApplication>
>#include <QDebug>
>#include <QProcess>
>#include "./example_invoker.h"
>
>int main(int argc, char *argv[])
>{
>    QCoreApplication a(argc, argv);
>
>    NotationExample::Invoker invoker;
>
>    qDebug()<<invoker.invokeBasePath("GET", "/api/insert", "{}").toString();
>
>    return QProcess::NormalExit;
>}
>```
