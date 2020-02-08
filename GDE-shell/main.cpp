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

#include <manager/desktopManager.hpp>

#include <QGuiApplication>
#include <QQuickWindow>
#include <QQmlEngine>
#include <QCommandLineParser>

using namespace Mgr;

int main(int argc, char *argv[]) {
    QGuiApplication::setFallbackSessionManagementEnabled(false);

    QQuickWindow::setDefaultAlphaBuffer(true);

    QGuiApplication app(argc, argv);

    QCoreApplication::setApplicationName("GDE-shell");
    QCoreApplication::setApplicationVersion("0.0.0");

    QCommandLineParser p;
    p.addHelpOption();
    p.addVersionOption();
    p.setApplicationDescription("Global Desktop Environment Shell");
    p.process(app);

    QQmlEngine engine;

    DesktopManager desktopManager(&engine);

    return app.exec();
}
