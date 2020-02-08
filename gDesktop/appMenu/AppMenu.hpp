/*
 * This file is part of GDE
 *
 * Copyright © 2020 Qusai Hroub
 *
 * GDE is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#ifndef APPMENU_HPP
#define APPMENU_HPP

#include <process.hpp>

#include <QObject>
#include <QVariant>
#include <QVariantList>

namespace Desktop {

    class AppMenu : public QObject {
        Q_OBJECT
    public:
        explicit AppMenu(QObject *parent = nullptr);
        ~AppMenu();

        Q_INVOKABLE QVariantList getAllApps();
        Q_INVOKABLE int updateAllApps();
        Q_INVOKABLE QVariantList getReacentApps();
        Q_INVOKABLE int updateReacentApps();
        Q_INVOKABLE void init();
        Q_INVOKABLE void allAppInit();

    private:
        QVariantList m_allApps;
        QVariantList m_reacentApps;
        Process *m_process = Process::createInstance();

        void exec(const QString &exec);

    signals:

    public slots:
    };
}

#endif // APPMENU_HPP
