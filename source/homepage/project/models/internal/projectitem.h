#ifndef PROJECTITEM_H
#define PROJECTITEM_H

#include <QString>
#include <QDateTime>
#include <QFileInfo>
#include <QMetaType>
#include <QDir>
#include "global_h.h"
#include "../datamodel/devicelistmodel.h"

class PROJECT_EXPORT ProjectItem {
public:
    ProjectItem();
    ProjectItem(const QString& name, const QString& path, const QDateTime& lastEditTime=QDateTime::currentDateTime());
    ~ProjectItem();
    //获取项目名称
    QString name() const;
    void setName(const QString &name);

    // 获取项目路径
    QString path() const;
    void path(const QString &path);

    // 获取项目大小（字节）
    qint64 size() const;

    // 获取最后编辑时间
    QDateTime lastEditTime() const;
    void setLastEditTime(const QDateTime &time);

    // 添加相等比较运算符
    bool operator==(const ProjectItem &other) const;

    //获取设备数量
    int deviceCount() const;

    // 获取设备模型
    DeviceListModel* deviceModel() const;
    void setDeviceModel(DeviceListModel* deviceModel);

private:
    QString m_name;
    QString m_path;
    QDateTime m_lastEditTime;
    QStringList m_thumbnailPaths;  // 存储4个缩略图的路径
    DeviceListModel* m_deviceModel;
};
Q_DECLARE_METATYPE(ProjectItem)
#endif // PROJECTITEM_H
