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

#pragma once

#include <QObject>
#include <QGuiApplication>
#include <QQuickView>
#include <QScreen>

namespace Mgr {
    class DesktopManager : public QObject {
        Q_OBJECT

    public:
        explicit DesktopManager(QQmlEngine *engine);

    private:
        QQmlEngine *m_engine;
        QGuiApplication *m_app;
        QScreen *m_primaryScreen;

    public slots:
        void primaryScreenChanged(QScreen *screen);
        void screenRemoved(const QScreen *screen);
        void screenAdded(const QScreen *screen);

    };
}
