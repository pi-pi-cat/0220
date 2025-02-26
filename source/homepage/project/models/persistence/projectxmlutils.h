#ifndef PROJECTXMLUTILS_H
#define PROJECTXMLUTILS_H

#include <QString>
#include <QList>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QDateTime>
#include <QDebug>

#include "../internal/deviceinfo.h"
#include "../internal/projectitem.h"

class ProjectXmlUtils
{
public:


    static ProjectItem* parseProjectFile(const QString& xmlFilePath);

    static QList<DeviceInfo> parseDevices(const QString& xmlFilePath);

    static QString getProjectName(const QString& xmlFilePath);

private:
    static DeviceInfo parseDeviceElement(const QDomElement& deviceElement);

    static bool openXmlFile(const QString& xmlFilePath, QDomDocument& document);

    ProjectXmlUtils();
    ~ProjectXmlUtils();
};

#endif // PROJECTXMLUTILS_H
