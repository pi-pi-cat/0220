#ifndef PROJECTLISTMODEL_H
#define PROJECTLISTMODEL_H

#include <QAbstractListModel>
#include "../internal/projectitem.h"

class ProjectListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SortRole {
        RecentUsed,
        ByName,
        BySize
    };
    ProjectListModel();

private:
    QList<ProjectItem> m_projects;
    SortRole m_sortRole;
    QString m_filterString;
};

#endif // PROJECTLISTMODEL_H
