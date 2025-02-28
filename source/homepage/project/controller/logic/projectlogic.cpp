#include "projectlogic.h"
#include "../../models/internal/projectitem.h"
#include "../../views/composites/projectgallery/projectgalleryview.h"
#include "../../models/persistence/configfileutils.h"
#include "../../models/persistence/projectxmlutils.h"
#include "../eventbus/eventbus.h"

ProjectLogic::ProjectLogic(QObject *parent) : QObject(parent),
    m_projectListModel(nullptr),
    m_galleryView(nullptr)
{
}

void ProjectLogic::setProjectListModel(ProjectListModel *model)
{
    m_projectListModel = model;
}

void ProjectLogic::setGalleryView(ProjectGalleryView *view)
{
    m_galleryView = view;
}

void ProjectLogic::createNewProject()
{
    if (m_projectListModel) {
        // 1. 创建新项目数据
        ProjectItem *newProject = m_projectListModel->createNewProject();
        // 2. 通知视图更新
        if (newProject && m_galleryView) {
             // 这里会创建新的ProjectCard并添加到视图中
            m_galleryView->onProjectAdded(*newProject);
        }
    }
}

void ProjectLogic::openProject(const ProjectItem &project)
{
    // 这里处理打开项目的逻辑
    qDebug() << "打开项目:" << project.name();

    // 通过事件总线通知DeviceMediator
    QVariant projectData;
    projectData.setValue(project);
    EventBus::getInstance().publish("OpenDeviceView", projectData);

    // 发出信号通知其他组件（比如主窗口）需要打开新界面
    emit projectOpened(project);
}

void ProjectLogic::deleteProject(const ProjectItem &project)
{
    if(m_projectListModel){
        // 1. 删除项目数据
        bool success = m_projectListModel->removeProject(project);
        // 2. 通知视图更新
        if (success && m_galleryView) {
             // 这里会创建新的ProjectCard并添加到视图中
            m_galleryView->onProjectRemoved(project);
        }
    }
}

void ProjectLogic::sortProjects(ProjectListModel::SortRole sortRole)
{
    if (m_projectListModel) {
        // 设置新的排序规则并应用
        m_projectListModel->setSortRole(sortRole);

        // 获取排序后的项目列表
        QList<ProjectItem> sortedProjects = m_projectListModel->getProjects();

        // 更新视图
        if (m_galleryView) {
            m_galleryView->sortCards(sortedProjects);
        }
    }
}

void ProjectLogic::loadInitialProjects()
{
    // 这里可以添加测试数据
    if (m_projectListModel && m_galleryView) {
        // 创建一些测试项目
        // ProjectItem *project1 = m_projectListModel->createNewProject();
        // ProjectItem *project2 = m_projectListModel->createNewProject();
        
        // // 更新视图
        // m_galleryView->onProjectAdded(*project1);
        // m_galleryView->onProjectAdded(*project2);
        QList<QString> projectPaths = ConfigFileUtils::getRecentProjectPaths("/Users/yxf/Documents/QtOnline/0220/files/recent.ini");//TODO 需要修改
        for(const QString& projectPath : projectPaths){
            ProjectItem* item = ProjectXmlUtils::parseProjectFile(projectPath);
            if(item){
                m_projectListModel->addExistProject(*item);
                m_galleryView->onProjectAdded(*item);
            }
        }
    }
}
