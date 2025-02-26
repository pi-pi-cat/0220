#include "projectxmlutils.h"

ProjectItem *ProjectXmlUtils::parseProjectFile(const QString &xmlFilePath)
{
    QDomDocument doc;
    if(!openXmlFile(xmlFilePath, doc)){
        return nullptr;
    }

    QDomElement root = doc.documentElement();
    if(root.tagName() != "project"){
        qWarning() << "无法获得project tag";
        return nullptr;
    }

    QString projectName = root.attribute("name");
    if (projectName.isEmpty()) {
        qWarning() << "Project name 不存在" << xmlFilePath;
        return nullptr;
    }
    ProjectItem* projectItem = new ProjectItem(projectName, xmlFilePath);//TODO 需要修改这里的路径为该文件的目录吗？

    //TODO 加入Device 和 修改时间

    // Count the number of devices
    int deviceCount = 0;
    QDomElement deviceElement = root.firstChildElement("device");
    while (!deviceElement.isNull()) {
        deviceCount++;
        deviceElement = deviceElement.nextSiblingElement("device");
    }

    projectItem->setDeviceCount(deviceCount);
    return projectItem;
}

QList<DeviceInfo> ProjectXmlUtils::parseDevices(const QString &xmlFilePath)
{
    QList<DeviceInfo> devices;

    QDomDocument doc;
    if (!openXmlFile(xmlFilePath, doc)) {
        return devices;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "project") {
        qWarning() << "Root element is not 'project' in:" << xmlFilePath;
        return devices;
    }

    // Iterate through all device elements
    QDomElement deviceElement = root.firstChildElement("device");
    while (!deviceElement.isNull()) {
        DeviceInfo device = parseDeviceElement(deviceElement);
        devices.append(device);
        deviceElement = deviceElement.nextSiblingElement("device");
    }

    return devices;
}

QString ProjectXmlUtils::getProjectName(const QString &xmlFilePath)
{
    QDomDocument doc;
    if (!openXmlFile(xmlFilePath, doc)) {
        return QString();
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "project") {
        qWarning() << "Root element is not 'project' in:" << xmlFilePath;
        return QString();
    }

    return root.attribute("name");
}

DeviceInfo ProjectXmlUtils::parseDeviceElement(const QDomElement &deviceElement)
{
    DeviceInfo device;

    // Get device name
    device.setName(deviceElement.attribute("name"));

    // Parse child elements
    QDomElement displayNameElement = deviceElement.firstChildElement("displayname");
    if (!displayNameElement.isNull()) {
        device.setDisplayName(displayNameElement.text());
    }

    QDomElement creationElement = deviceElement.firstChildElement("creation");
    if (!creationElement.isNull()) {
        device.setCreationTime(QDateTime::fromString(creationElement.text(), "yyyy-MM-dd hh:mm:ss:zzz"));
    }

    QDomElement modificationElement = deviceElement.firstChildElement("modification");
    if (!modificationElement.isNull()) {
        device.setModificationTime(QDateTime::fromString(modificationElement.text(), "yyyy-MM-dd hh:mm:ss:zzz"));
    }

    QDomElement descriptionElement = deviceElement.firstChildElement("description");
    if (!descriptionElement.isNull()) {
        device.setDescription(descriptionElement.text());
    }

    QDomElement statusElement = deviceElement.firstChildElement("status");
    if (!statusElement.isNull()) {
        device.setStatus(statusElement.text());
    }

    return device;
}

bool ProjectXmlUtils::openXmlFile(const QString &xmlFilePath, QDomDocument &document)
{
    QFile file(xmlFilePath);
    if (!file.exists()){
        qWarning() << "xml文件不存在";
        return false;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open XML file:" << xmlFilePath << "Error:" << file.errorString();
        return false;
    }
    QString errorMsg;
    int errorLine, errorColumn;
    if (!document.setContent(&file, &errorMsg, &errorLine, &errorColumn)) {
        qWarning() << "Parse error in" << xmlFilePath << "at line" << errorLine
                   << "column" << errorColumn << ":" << errorMsg;
        file.close();
        return false;
    }

    file.close();
    return true;
}
