#ifndef GDESKTOP_GLOBAL_H
#define GDESKTOP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GDESKTOP_LIBRARY)
#  define GDESKTOP_EXPORT Q_DECL_EXPORT
#else
#  define GDESKTOP_EXPORT Q_DECL_IMPORT
#endif

#endif // GDESKTOP_GLOBAL_H
