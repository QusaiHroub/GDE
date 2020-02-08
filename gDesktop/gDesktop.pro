TEMPLATE = lib
DEFINES += GDESKTOP_LIBRARY

CONFIG += c++11
QT += qml widgets quick

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += /usr/include/KF5/KWindowSystem \
        /usr/include/KF5/ \
        /usr/include/kde4
LIBS += -lKF5WindowSystem

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appMenu/AppMenu.cpp \
    appMenu/MenuButton.cpp \
    gdesktop.cpp \
    manager/desktopManager.cpp

HEADERS += \
    appMenu/AppMenu.hpp \
    appMenu/MenuButton.hpp \
    gDesktop_global.h \
    gdesktop.hpp \
    manager/desktopManager.hpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gDesktop.qrc

unix:!macx: LIBS += -L$$OUT_PWD/../gxdg/ -lgxdg
LIBS += -L/usr/lib/ -lgxdg

INCLUDEPATH += $$PWD/../gxdg
DEPENDPATH += $$PWD/../gxdg
