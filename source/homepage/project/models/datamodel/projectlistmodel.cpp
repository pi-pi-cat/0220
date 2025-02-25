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

bool ProjectListModel::removeProject(const ProjectItem &project)
{
    for(int i = 0; i < m_projects.size(); ++i){
        if(m_projects[i].path() == project.path() && m_projects[i].name() == project.name()){
            beginRemoveRows(QModelIndex(), i, i);
            m_projects.removeAt(i);
            endRemoveRows();
            return true;
        }
    }
    return false;
}

void ProjectListModel::setSortRole(SortRole role)
{
    if (m_sortRole != role) {
        m_sortRole = role;
        applySort();  // 当排序角色改变时重新排序
    }
}

QList<ProjectItem> ProjectListModel::getSortedProjects() const
{
    QList<ProjectItem> sortedList = m_projects;

    switch (m_sortRole) {
    case ByName:
        std::sort(sortedList.begin(), sortedList.end(), [](const ProjectItem &a, const ProjectItem &b) {
            return a.name().toLower() < b.name().toLower();  // 不区分大小写
        });
        break;

    case BySize:
        std::sort(sortedList.begin(), sortedList.end(), [](const ProjectItem &a, const ProjectItem &b) {
            return a.size() > b.size();  // 从大到小排序
        });
        break;

    case RecentUsed:
    default:
        // 现有顺序就是最近使用顺序，
        std::sort(sortedList.begin(), sortedList.end(), [](const ProjectItem &a, const ProjectItem &b) {
            return a.lastEditTime() > b.lastEditTime();  // 最近使用的排在前面
        });
        break;
    }

    return sortedList;
}

void ProjectListModel::applySort()
{
    // 如果列表为空，无需排序
    if (m_projects.isEmpty())
        return;

    // 获取排序后的列表
    QList<ProjectItem> newOrder = getSortedProjects();

    // 检查是否有顺序变化
    bool orderChanged = false;
    if (m_projects.size() == newOrder.size()) {
        for (int i = 0; i < m_projects.size(); ++i) {
            if (!(m_projects[i] == newOrder[i])) {
                orderChanged = true;
                break;
            }
        }
    } else {
        orderChanged = true;
    }

    // 如果顺序没变，就不需要更新
    if (!orderChanged)
        return;

    // 更新模型数据
    beginResetModel();
    m_projects = newOrder;
    endResetModel();
}
