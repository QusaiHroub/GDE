/*
 * This file is part of GDE
 *
 * Copyright © 2020 QusaiHroub
 *
 * GDE is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#include <QApplication>
#include <QQuickWindow>
#include <QCommandLineParser>

int main(int argc, char *argv[]) {
    QGuiApplication::setFallbackSessionManagementEnabled(false);

    QQuickWindow::setDefaultAlphaBuffer(true);

    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("GDE-shell");
    QCoreApplication::setApplicationVersion("0.0.0");

    QCommandLineParser p;
    p.addHelpOption();
    p.addVersionOption();
    p.setApplicationDescription("Global Desktop Environment Shell");
    p.process(app);

    return app.exec();
}
