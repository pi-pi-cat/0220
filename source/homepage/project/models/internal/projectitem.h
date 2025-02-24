#ifndef PROJECTITEM_H
#define PROJECTITEM_H

#include <QString>
#include <QDateTime>

class ProjectItem {
public:
    QString name;
    QString path;
    QDateTime lastEditTime;
    QStringList thumbnailPaths;  // 存储4个缩略图的路径

    ProjectItem();
    ProjectItem(const QString& name, const QString& path);
};

#endif // PROJECTITEM_H
