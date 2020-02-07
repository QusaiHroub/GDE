#pragma once
#include <QProcess>
#include <QVariant>
#include <QDebug>

#include "gxdg_global.h"

class GXDG_EXPORT Process : public QProcess {
    Q_OBJECT

public:
    static Process *getInstance();
    static void releaseInstance();

    Q_INVOKABLE void start(const QString &program, const QVariantList &arguments = QVariantList());

    Q_INVOKABLE QByteArray readAll();

private:
    Process(QObject *parent = nullptr);

    static void addRef();
    static void releasRef();

    static Process *instance;
    static int instanceCounter;

};
