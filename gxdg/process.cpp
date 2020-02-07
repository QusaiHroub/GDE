#include "process.hpp"

Process *Process::instance = nullptr;
int Process::instanceCounter = 0;

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

Process *Process::getInstance() {
    addRef();

    if (instance == nullptr) {
        instance = new Process();
    }

    return instance;
}

void Process::releaseInstance() {
    releasRef();

    if (instanceCounter <= 0 && instance != nullptr) {
        instanceCounter = 0;
        delete instance;
        instance = nullptr;
    }
}

void Process::addRef(){
    ++instanceCounter;
}

void Process::releasRef(){
    --instanceCounter;
}
