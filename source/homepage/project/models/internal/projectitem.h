#ifndef PROJECTITEM_H
#define PROJECTITEM_H

#include <QString>
#include <QDateTime>
#include "global_h.h"

class PROJECT_EXPORT ProjectItem {
public:
    ProjectItem();
    ProjectItem(const QString& name, const QString& path);

    QString name() const;
    void setName(const QString &name);
    QString path() const;
    void path(const QString &path);

private:
    QString m_name;
    QString m_path;
    QDateTime m_lastEditTime;
    QStringList m_thumbnailPaths;  // 存储4个缩略图的路径
};

#endif // PROJECTITEM_H
