#ifndef GXDG_GLOBAL_H
#define GXDG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GXDG_LIBRARY)
#  define GXDG_EXPORT Q_DECL_EXPORT
#else
#  define GXDG_EXPORT Q_DECL_IMPORT
#endif

#endif // GXDG_GLOBAL_H
