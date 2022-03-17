#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
#include "./example_invoker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NotationExample::Invoker invoker;

    qDebug()<<invoker.invokeBasePath("GET", "/api/insert", "{}").toString();

    return QProcess::NormalExit;
}
