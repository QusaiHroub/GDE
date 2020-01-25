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

#ifndef GDESKTOP_GLOBAL_H
#define GDESKTOP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GDESKTOP_LIBRARY)
#  define GDESKTOP_EXPORT Q_DECL_EXPORT
#else
#  define GDESKTOP_EXPORT Q_DECL_IMPORT
#endif

#endif // GDESKTOP_GLOBAL_H
