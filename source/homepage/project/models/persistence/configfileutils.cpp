#include "configfileutils.h"

QList<QString> ConfigFileUtils::getRecentProjectPaths(const QString &configFilePath)
{
    QList<QString> projectPaths;

    QFileInfo fileinfo(configFilePath);
    if(!fileinfo.exists() || !fileinfo.isReadable()){
        qWarning() << "无法读取最近工程配置文件";
        return projectPaths;
    }

    QSettings settings(configFilePath, QSettings::IniFormat);//TODO 修复无法读取分组问题
    // qDebug() << "QSettings 状态:" << settings.status();
    // qDebug() << "所有分组:" << settings.childGroups();  // 打印所有分组
    // qDebug() << settings.allKeys();
    // settings.setValue("p1", "/Users/yxf/Documents/QtOnline/0220/files/1/1.xml");
    // settings.setValue("p2", "/Users/yxf/Documents/QtOnline/0220/files/2/2.xml");
    // settings.setValue("p3", "/Users/yxf/Documents/QtOnline/0220/files/3/3.xml");

    // if (settings.isWritable()){
    //     qDebug() <<"can write";
    // }
    // settings.beginGroup("General");
    qDebug() << settings.allKeys();
    qDebug() << "当前分组:" << settings.group();  // 打印当前分组

    QStringList keys = settings.allKeys();
    for(const QString &key:keys){
        QString path = settings.value(key).toString();
        if(!path.isEmpty()){
            projectPaths.append(path);
        }
    }

    // settings.endGroup();
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
