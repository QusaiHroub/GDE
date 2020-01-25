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

#ifndef GDESKTOP_HPP
#define GDESKTOP_HPP

#include "gDesktop_global.h"

#include <QQuickView>
#include <QScreen>

namespace Desktop {

    class GDESKTOP_EXPORT GDesktop : public QQuickView {
        Q_OBJECT

    public:
        explicit GDesktop(QQmlEngine *engine, const QScreen *screen);
        void updateGeometry(const QRect &geometry);
    private:
        const QScreen *m_screen;
    };
}


#endif // GDESKTOP_HPP
