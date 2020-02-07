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

#ifndef MENUBUTTON_HPP
#define MENUBUTTON_HPP

#include <QObject>
#include <QIcon>

namespace Desktop {

    class MenuButton : public QObject {
        Q_OBJECT
        Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
        Q_PROPERTY(QString exec READ exec WRITE setExec NOTIFY execChanged)
        Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
        Q_PROPERTY(QString comment READ comment WRITE setComment NOTIFY commentChanged)
        Q_PROPERTY(QString iconName READ iconName WRITE setIconName NOTIFY iconNameChanged)
        Q_PROPERTY(QIcon icon READ icon WRITE setIcon NOTIFY iconChanged)
        Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

    public:
            explicit MenuButton(QObject *parent = nullptr);

            QString name() const;
                void setName(const QString &name);
            QString exec() const;
                void setExec(const QString &exec);
            QString path() const;
                void setPath(const QString &path);
            QString comment() const;
                void setComment(const QString &comment);
            QString iconName() const;
                void setIconName(const QString &iconName);
            QIcon icon() const;
                void setIcon(const QIcon &icon);
            QString color() const;
                void setColor(const QString &color);

    signals:
            void nameChanged(const QString &name);
            void execChanged(const QString &exec);
            void pathChanged(const QString &path);
            void commentChanged(const QString &comment);
            void iconChanged(const QIcon &icon);
            void iconNameChanged(const QString &iconName);
            void colorChanged(const QString &color);

            Q_INVOKABLE void execApp(const QString &exec);

    private:
            QString m_name;
            QString m_exec;
            QString m_path;
            QString m_comment;
            QString m_iconName;
            QIcon m_icon;
            QString m_color;

    public slots:
    };
}

#endif // MENUBUTTON_HPP
