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
#include <QDesktopWidget>

namespace Mgr {
    DesktopManager::DesktopManager(QQmlEngine *engine)
        : m_engine(engine) {

    }
}
