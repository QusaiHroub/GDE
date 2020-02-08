#ifndef SHELLMANAGER_HPP
#define SHELLMANAGER_HPP

#include <manager/desktopManager.hpp>

#include <QObject>

namespace Mgr {

    class ShellManager : public QObject {
        Q_OBJECT
    public:
        explicit ShellManager(QQmlEngine *engine);

    private:
        QScopedPointer<DesktopManager> m_desktopManager;

    signals:

    public slots:
    };

}

#endif // SHELLMANAGER_HPP
