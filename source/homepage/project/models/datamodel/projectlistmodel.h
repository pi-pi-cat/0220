#ifndef PROJECTLISTMODEL_H
#define PROJECTLISTMODEL_H

#include <QAbstractListModel>
#include "global_h.h"
#include "../internal/projectitem.h"

class PROJECT_EXPORT ProjectListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SortRole {
        RecentUsed,
        ByName,
        BySize
    };
    ProjectListModel(QObject* parent = nullptr);

    // 必需实现的纯虚函数
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    // 添加新项目的方法
    ProjectItem* createNewProject();

private:
    QList<ProjectItem> m_projects;
    SortRole m_sortRole;
    QString m_filterString;
};

#endif // PROJECTLISTMODEL_H
