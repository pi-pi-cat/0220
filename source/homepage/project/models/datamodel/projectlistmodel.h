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

    // 添加项目
    ProjectItem* createNewProject(const QString& name = QString(), const QString& path=QString());
    // 添加已有的项目
    void addExistProject(const ProjectItem& item);
    // 移除项目
    bool removeProject(const ProjectItem &project);

    //排序相关
    void setSortRole(SortRole role);
    SortRole sortRole() const { return m_sortRole; }
    // 获取排序后的项目列表
    QList<ProjectItem> getSortedProjects() const;

    // 应用排序并更新模型
    void applySort();

    QList<ProjectItem> getProjects() const {return m_projects;}

private:
    QList<ProjectItem> m_projects;
    SortRole m_sortRole;
    QString m_filterString;
};

#endif // PROJECTLISTMODEL_H
