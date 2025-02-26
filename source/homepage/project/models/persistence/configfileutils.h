#ifndef CONFIGFILEUTILS_H
#define CONFIGFILEUTILS_H

#include <QMap>
#include <QString>
#include <QDebug>
#include <QSettings>
#include <QFileInfo>

class ConfigFileUtils
{
public:

    static QMap<QString, QString> getRecentProjectPaths(const QString& configFilePath = "recent.ini");
    static bool addRecentProject(const QString& projectKey, const QString& projectPath,
                                 const QString& configFilePath = "recent.ini");

private:
    ConfigFileUtils();
    ~ConfigFileUtils();
};

#endif // CONFIGFILEUTILS_H
