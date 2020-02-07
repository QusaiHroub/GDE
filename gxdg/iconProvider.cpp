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

#include "iconProvider.hpp"

#include <QIcon>

namespace Desktop {
    IconProvider *IconProvider::m_instance = nullptr;
    int IconProvider::m_instanceCounter = 0;

    IconProvider::IconProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap) {
    }

    QObject *IconProvider::createInstance(QQmlEngine *engine, QJSEngine *scriptEngine) {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        return createInstance();
    }

    IconProvider *IconProvider::createInstance() {
        addRef();

        if (m_instance == nullptr) {
            m_instance = new IconProvider();
        }
        return m_instance;
    }

    void IconProvider::releaseInstance() {
        releasRef();

        if (m_instanceCounter <= 0 && m_instance != nullptr) {
            m_instanceCounter = 0;
            delete m_instance;
            m_instance = nullptr;
        }
    }

    void IconProvider::addRef(){
        ++m_instanceCounter;
    }

    void IconProvider::releasRef(){
        --m_instanceCounter;
    }

    QPixmap IconProvider::requestPixmap(const QString &id, QSize *size,
                                             const QSize &requestedSize) {
        static const int fallbackSize = 32;

        QIcon ico = QIcon::fromTheme(id);
        QPixmap pix;

        if (requestedSize.isValid()) {
            pix = ico.pixmap(requestedSize);
        } else {
            pix = ico.pixmap(fallbackSize, fallbackSize);
        }
        if (size != nullptr) {
            *size = pix.size();
        }
        return pix;
    }
}
