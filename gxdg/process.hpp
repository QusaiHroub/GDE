#pragma once
#include <QProcess>
#include <QVariant>
#include <QDebug>

#include "gxdg_global.h"

class GXDG_EXPORT Process : public QProcess {
    Q_OBJECT

public:
    Process(QObject *parent = nullptr);

    Q_INVOKABLE void start(const QString &program, const QVariantList &arguments = QVariantList());

    Q_INVOKABLE QByteArray readAll();
};
