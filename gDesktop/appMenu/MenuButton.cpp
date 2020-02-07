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

#include "MenuButton.hpp"

namespace Desktop {
    MenuButton::MenuButton(QObject *parent) : QObject(parent) {

    }

    QString MenuButton::name() const {
        return m_name;
    }

    void MenuButton::setName(const QString &name) {
        if (name != m_name) {
            m_name = name;
            if (m_name.size() > 12) {
                m_name.resize(12);
                for (int i = 11 ; i >= 9 ; i--)
                    m_name[i] = '.';
            }
            emit nameChanged(m_name);
        }
    }

    QString MenuButton::exec() const {
        return m_exec;
    }

    void MenuButton::setExec(const QString &exec) {
        if (exec != m_exec) {
            m_exec = exec;
            emit execChanged(m_exec);
        }
    }

    QString MenuButton::path() const {
        return m_path;
    }

    void MenuButton::setPath(const QString &path) {
        if (path != m_path) {
            m_path = path;
            emit pathChanged(m_path);
        }
    }

    QString MenuButton::comment() const {
        return m_comment;
    }

    void MenuButton::setComment(const QString &comment) {
        if (comment != m_comment) {
            m_comment = comment;
            emit commentChanged(m_comment);
        }
    }

    QString MenuButton::iconName() const {
        return m_iconName;
    }

    void MenuButton::setIconName(const QString &iconName) {
        if (iconName != m_iconName) {
            m_iconName = iconName;
            emit iconNameChanged(m_iconName);
        }
    }

    QString MenuButton::color() const {
        return m_color;
    }

    void MenuButton::setColor(const QString &color) {
        if (color != m_color) {
            m_color = color;
            emit colorChanged(m_color);
        }
    }

    QIcon MenuButton::icon() const {
        return m_icon;
    }

    void MenuButton::setIcon(const QIcon &icon) {
            emit iconChanged(icon);
    }
}
