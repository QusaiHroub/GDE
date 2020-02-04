

#pragma once

#include <QHash>
#include <QObject>
#include <QSharedPointer>

#include "gxdg_global.h"

namespace Desktop {
    /**
     * IniFile allows us to safely parse unix-style INI files for use in
     * .desktop file parsing.
     * Unlike the QSettings alternative, it will actually ensure ';' is respected
     * as a separator for arrays.
     */
    class GXDG_EXPORT IniFile : public QObject {
        Q_OBJECT

    public:
        explicit IniFile();
        explicit IniFile(const QString &path);

        /**
         * Determine if this INI file is actually valid
         */
        bool isValid();

        /**
         * Grab a string from the map if it exists
         */
        const QString getString(const QString &sectionID, const QString &key,
                                const QString &fallback = QStringLiteral(""));

        /**
         * Return a QStringList for the given key
         *
         * This is typically separated by the ; character.
         */
        const QStringList getStringList(const QString &sectionID, const QString &key,
                                        const QStringList &fallback = QStringList());

        /**
         * Get a boolean value from the map. This will return false by default if the value
         * is unknown.
         */
        bool getBool(const QString &sectionID, const QString &key, bool fallback = false);

        /**
         * Get an integer value from the Ini File
         */
        int getInt(const QString &sectionID, const QString &key, int fallback = 0);

        /**
         * Simple validation - figure out if the section actually exists or not.
         */
        bool hasSection(const QString &sectionID);

    private:
        QHash<QString, QSharedPointer<QHash<QString, QString>>> mapping;
        const QString path;
        bool valid;
    };
}
