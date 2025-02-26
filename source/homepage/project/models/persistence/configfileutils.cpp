#include "configfileutils.h"

QMap<QString, QString> ConfigFileUtils::getRecentProjectPaths(const QString &configFilePath)
{
    QMap<QString, QString> projectPaths;

    QFileInfo fileinfo(configFilePath);
    if(!fileinfo.exists() || !fileinfo.isReadable()){
        qWarning() << "无法读取最近工程配置文件";
        return projectPaths;
    }

    QSettings settings(configFilePath, QSettings::IniFormat);
    settings.beginGroup("General");

    QStringList keys = settings.childKeys();
    for(const QString &key:keys){
        QString path = settings.value(key).toString();
        if(!path.isEmpty()){
            projectPaths.insert(key, path);
        }
    }

    settings.endGroup();
    return projectPaths;
}

bool ConfigFileUtils::addRecentProject(const QString &projectKey, const QString &projectPath, const QString &configFilePath)
{
    if (projectKey.isEmpty() || projectPath.isEmpty()) {
        qWarning() << "Project key or path is empty";
        return false;
    }

    QSettings settings(configFilePath, QSettings::IniFormat);
    settings.beginGroup("General");
    settings.setValue(projectKey, projectPath);
    settings.endGroup();

    return settings.status() == QSettings::NoError;
}

ConfigFileUtils::ConfigFileUtils() {}
