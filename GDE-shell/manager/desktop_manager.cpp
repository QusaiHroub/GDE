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

#include "desktop_manager.hpp"

#include <QDebug>
#include <QScreen>
#include <QGuiApplication>

namespace Mgr {
    DesktopManager::DesktopManager(QQmlEngine *engine)
        : m_engine(engine), m_primaryScreen(QGuiApplication::primaryScreen()) {

        m_app = dynamic_cast<QGuiApplication *>(QGuiApplication::instance());
        connect(m_app, &QGuiApplication::primaryScreenChanged, this, &DesktopManager::primaryScreenChanged);
        connect(m_app, &QGuiApplication::screenAdded, this, &DesktopManager::screenAdded);
        connect(m_app, &QGuiApplication::screenRemoved, this, &DesktopManager::screenRemoved);

        for (auto screen : QGuiApplication::screens()) {
            screenAdded(screen);
        }
    }

    //This signal is emitted whenever a primary screen has been changed.
    void DesktopManager::primaryScreenChanged(QScreen *screen) {
        m_primaryScreen = screen;
        qDebug() << "New primary: " << m_primaryScreen->name();
    }

    //This signal is emitted whenever a new screen has been removed from the system.
    void DesktopManager::screenRemoved(const QScreen *screen) {

        qDebug() << "Screen removed:" << screen->name() << "Bye Bye";

        m_desktops.remove(screen->name());
    }

    //This signal is emitted whenever a new screen has been added to the system.
    void DesktopManager::screenAdded(const QScreen *screen) {

        qDebug() << "Screen added:" << screen->name();

        //Temporarily use screen name as a key.
        m_desktops.insert(screen->name(), QSharedPointer<Desktop::GDesktop>(new Desktop::GDesktop(m_engine, screen)));
    }
}
