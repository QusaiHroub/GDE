#include "process.hpp"

Process::Process(QObject *parent) : QProcess(parent) {

}

void Process::start(const QString &program, const QVariantList &arguments) {
    QStringList args;

    qDebug() << "Running" << program;

    for (int i = 0; i < arguments.length(); i++)
        args << arguments[i].toString();

    QProcess::startDetached(program);
}

QByteArray Process::readAll() {
    return QProcess::readAll();
}
