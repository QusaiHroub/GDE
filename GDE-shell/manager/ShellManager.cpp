#include "ShellManager.hpp"

namespace Mgr {
    ShellManager::ShellManager(QQmlEngine *engine) {
        m_desktopManager.reset(new DesktopManager(engine));
    }
}

