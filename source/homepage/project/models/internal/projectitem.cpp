#include "projectitem.h"

ProjectItem::ProjectItem()
{

}

ProjectItem::ProjectItem(const QString &name, const QString &path, const QDateTime &lastEditTime)
{
    m_name = name;
    m_path = path;
    m_lastEditTime = lastEditTime;
}

qint64 ProjectItem::size() const
{
    // 如果路径是目录，递归计算目录大小
    QFileInfo fileInfo(m_path);
    if (!fileInfo.exists())
        return 0;

    if (fileInfo.isFile())
        return fileInfo.size();

    // 递归计算文件夹大小
    qint64 totalSize = 0;
    QDir dir(m_path);

    // 获取所有文件和目录
    QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QFileInfo &fi : fileList) {
        if (fi.isFile())
            totalSize += fi.size();
        else if (fi.isDir()) {
            // 对于子目录，创建临时 ProjectItem 来计算大小
            ProjectItem subItem(fi.fileName(), fi.absoluteFilePath());
            totalSize += subItem.size();
        }
    }

    return totalSize;
}


QString ProjectItem::name() const
{
    return m_name;
}

void ProjectItem::setName(const QString &name)
{
    m_name = name;
}

QString ProjectItem::path() const
{
    return m_path;
}

void ProjectItem::path(const QString &path)
{
    m_path = path;
}

QDateTime ProjectItem::lastEditTime() const
{
    return m_lastEditTime;
}

void ProjectItem::setLastEditTime(const QDateTime &time)
{
    m_lastEditTime = time;
}

bool ProjectItem::operator==(const ProjectItem &other) const
{
    return m_path == other.m_path && m_name == other.m_name;
}

int ProjectItem::getDeivceCount() const
{
    return m_deviceCount;
}

void ProjectItem::setDeviceCount(const int &count)
{
    m_deviceCount = count;
}
