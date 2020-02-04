
#include "iniParser.hpp"

#include <QDebug>
#include <QFile>

namespace Desktop {
    IniFile::IniFile() : QObject(), valid(false) {
    }

    IniFile::IniFile(const QString &path) : QObject(), path(path), valid(false) {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }

        static const auto sectionStart = QStringLiteral("[");
        static const auto sectionEnd = QStringLiteral("]");
        static const auto fieldSep = QStringLiteral("=");
        static const auto commentNorm = QStringLiteral("#");
        static const auto commentWin = QStringLiteral(";");

        QTextStream input(&file);

        QHash<QString, QString> *sectionPtr = nullptr;

        while (!input.atEnd()) {
            auto line = input.readLine().trimmed();

            if (line.isEmpty()) {
                continue;
            }

            if (line.startsWith(commentNorm) || line.startsWith(commentWin)) {
                continue;
            }

            auto len = line.length();
            if (line[0] == sectionStart && line[len - 1] == sectionEnd) {
                line.remove(len - 1, 1);
                line.remove(0, 1);
                if (!mapping.contains(line)) {
                    mapping.insert(line,
                                   QSharedPointer<QHash<QString, QString>>(
                                       new QHash<QString, QString>()));

                    sectionPtr = mapping[line].data();
                }
                continue;
            }

            if (!line.contains(fieldSep)) {
                continue;
            }

            if (sectionPtr == nullptr) {
                qWarning() << "Invalid INI file has no sections: " << path;
                return;
            }

            auto splits = line.split(fieldSep);
            const auto splitsLen = splits.length();
            const auto key = splits[0].trimmed();
            if (splitsLen < 2) {
                qWarning() << "INI file has missing value for key '" << key << "' @ " << path;
                continue;
            }
            splits.removeFirst();
            auto val = splits.join(fieldSep).trimmed();

            sectionPtr->insert(key, val);
        }

        valid = true;
    }

    bool IniFile::isValid() {
        return this->valid;
    }

    const QString IniFile::getString(const QString &sectionID, const QString &key,
                                     const QString &fallback) {
        if (!mapping.contains(sectionID)) {
            return fallback;
        }
        return mapping[sectionID]->value(key, fallback).trimmed();
    }

    const QStringList IniFile::getStringList(const QString &sectionID, const QString &key,
                                             const QStringList &fallback) {
        if (!mapping.contains(sectionID)) {
            return fallback;
        }
        auto section = mapping[sectionID];
        if (!section->contains(key)) {
            return fallback;
        }
        return section->value(key).trimmed().split(";");
    }

    bool IniFile::getBool(const QString &sectionID, const QString &key, bool fallback) {

        static const auto sTrue = QStringLiteral("true");
        static const auto sYes = QStringLiteral("yes");
        static const auto sFalse = QStringLiteral("false");

        auto ret = this->getString(sectionID, key, fallback ? sTrue : sFalse).toLower();

        if (ret.compare(sTrue, Qt::CaseInsensitive) == 0 ||
            ret.compare(sYes, Qt::CaseInsensitive) == 0) {
            return true;
        }
        return false;
    }

    int IniFile::getInt(const QString &sectionID, const QString &key, int fallback) {
        if (!mapping.contains(sectionID)) {
            return fallback;
        }
        auto section = mapping[sectionID];
        if (!section->contains(key)) {
            return fallback;
        }
        return section->value(key).trimmed().toInt();
    }

    bool IniFile::hasSection(const QString &sectionID) {
        return mapping.contains(sectionID);
    }
}
