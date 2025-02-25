#include "projectlistmodel.h"



ProjectListModel::ProjectListModel(QObject *parent)
    :QAbstractListModel(parent),
    m_sortRole(RecentUsed),
    m_filterString("")
{

}

int ProjectListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_projects.size();
}

QVariant ProjectListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_projects.size())
        return QVariant();

    const ProjectItem &item = m_projects.at(index.row());

    switch (role) {
    case Qt::DisplayRole:
        return item.name(); // 假设ProjectItem有name()方法

    case Qt::DecorationRole:
        return item.path(); // 假设ProjectItem有icon()方法

    // 可以添加其他角色...

    default:
        return QVariant();
    }
}

ProjectItem *ProjectListModel::createNewProject()
{
    // 创建新项目的逻辑
    ProjectItem newItem(QString("新项目 %1").arg(m_projects.size() + 1), "test_path"); // 假设ProjectItem有默认构造函数
    // 通知视图开始插入行
    beginInsertRows(QModelIndex(), m_projects.size(), m_projects.size());

    // 添加到列表中
    m_projects.append(newItem);

    // 通知视图插入完成
    endInsertRows();

    return &m_projects.last();
}
