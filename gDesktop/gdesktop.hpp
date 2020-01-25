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
