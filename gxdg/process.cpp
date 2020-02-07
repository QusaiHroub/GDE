#include "process.hpp"

Process *Process::m_instance = nullptr;
int Process::m_instanceCounter = 0;

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

Process *Process::createInstance() {
    addRef();

    if (m_instance == nullptr) {
        m_instance = new Process();
    }

    return m_instance;
}

QObject *Process::createInstance(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return createInstance();
}

void Process::releaseInstance() {
    releasRef();

    if (m_instanceCounter <= 0 && m_instance != nullptr) {
        m_instanceCounter = 0;
        delete m_instance;
        m_instance = nullptr;
    }
}

void Process::addRef(){
    ++m_instanceCounter;
}

void Process::releasRef(){
    --m_instanceCounter;
}
