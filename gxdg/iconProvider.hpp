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

#include <QPixmap>
#include <QQuickImageProvider>

#include "gxdg_global.h"

namespace Desktop {
    class GXDG_EXPORT IconProvider : public QObject, public QQuickImageProvider {
        Q_OBJECT

    public:
        static IconProvider *createInstance();
        static void releaseInstance();

        static QObject *createInstance(QQmlEngine *engine, QJSEngine *scriptEngine);

        QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

    private:
        explicit IconProvider();

        static void addRef();
        static void releasRef();

        static IconProvider *m_instance;
        static int m_instanceCounter;
    };
}
