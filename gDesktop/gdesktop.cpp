#include "gdesktop.hpp"

#include <KWindowSystem>

namespace Desktop {

    GDesktop::GDesktop(QQmlEngine *engine, const QScreen *screen)
        : QQuickView(engine, nullptr), m_screen(screen) {

        connect(m_screen, &QScreen::geometryChanged, this, &GDesktop::updateGeometry);

        setProperty("_q_showWithoutActivating", QVariant(true));
        setFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint | Qt::Tool);
        KWindowSystem::setState( winId(), NET::SkipTaskbar | NET::SkipPager );
        resize(0, 0);

        // Parent size dictates QML size
        setResizeMode(QQuickView::SizeRootObjectToView);
        setSource(QUrl("qrc:/qml/desktop_back_drop.qml"));

        updateGeometry(m_screen->geometry());
    }

    void GDesktop::updateGeometry(const QRect &geometry) {

        hide();
        setMaximumWidth(geometry.width());
        setMaximumHeight(geometry.height());
        setWidth(geometry.width());
        setHeight(geometry.height());
        setPosition(geometry.x(), geometry.y());
        show();

        qDebug() << m_screen->name() <<  "Desktop new height:" << height() << "px new width:" << width() << "px";

        KWindowSystem::setType(winId(), NET::WindowType::Desktop);
    }
}
