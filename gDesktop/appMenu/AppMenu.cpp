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

#include "AppMenu.hpp"
#include "MenuButton.hpp"

#include <DesktopFile.hpp>

#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFileInfo>
#include <QColor>
#include <random>
#include <cmath>
#include <QFile>


namespace Desktop {

    AppMenu::AppMenu(QObject *parent) : QObject(parent) {
        init();
    }

    void AppMenu::init() {
        allAppInit();
    }

    void AppMenu::exec(const QString &exec) {
        qDebug() <<  ("Exec: " + exec);
        m_process.start(exec);
    }

    void AppMenu::allAppInit() {
        QVariant allApp;
        m_allApps.clear();
        QString dir_str[2] = {"/usr/share/applications",
                            "/usr/local/share/applications"};
        for ( int i = 0 ; i < 2 ; i ++ ) {
            QDir dir(dir_str[i]);

            if (!dir.exists()) {
                qDebug() << "Skipping non-existent directory: " << dir;
                continue;
            }
            QDirIterator iter(dir);
            while (iter.hasNext()) {
                iter.next();
                QString base = iter.fileName();
                if (base == "." || base == "..") {
                    continue;
                }
                if (!base.endsWith(".desktop")) {
                    continue;
                }
                auto desktopFile = new DesktopFile(iter.filePath());
                if (!desktopFile->isValid()) {
                    qDebug() << "Skipping invalid desktop file: " << iter.filePath();
                    delete desktopFile;
                    continue;
                }
                if (!desktopFile->visible() ||
                    !desktopFile->canShowInDesktop(QStringLiteral("GDE"))) {
                    delete desktopFile;
                    continue;
                }
                QColor color;
                color.setRgb(std::abs(rand() % 256),std::abs(rand() % 256), std::abs(rand() % 256));
                QString exec = desktopFile->exec();
                exec = exec.remove("\"").remove(QRegExp(" %."));
                auto menuButton = new MenuButton(this);
                connect(menuButton, &MenuButton::execApp, this, &AppMenu::exec);
                menuButton->setName(desktopFile->name());
                menuButton->setExec(exec);
                menuButton->setPath(iter.filePath());
                menuButton->setComment(desktopFile->commentLocal());
                menuButton->setIcon(desktopFile->icon());
                menuButton->setIconName(desktopFile->iconName());
                menuButton->setColor(color.name());

                allApp.setValue(menuButton);
                m_allApps.append(allApp);
            }
        }
    }
}
