#include "projectlogic.h"
#include "../../models/datamodel/projectlistmodel.h"
#include "../../models/internal/projectitem.h"
#include "../../views/composites/galleryview/galleryview.h"

ProjectLogic::ProjectLogic(QObject *parent) : QObject(parent),
    m_projectListModel(nullptr),
    m_galleryView(nullptr)
{
}

void ProjectLogic::setProjectListModel(ProjectListModel *model)
{
    m_projectListModel = model;
}

void ProjectLogic::setGalleryView(GalleryView *view)
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
    qDebug() << "Opening project:" << project.name();

    // 发出信号通知其他组件（比如主窗口）需要打开新界面
    emit projectOpened(project);
}

void ProjectLogic::loadInitialProjects()
{
    // 这里可以添加测试数据
    if (m_projectListModel && m_galleryView) {
        // 创建一些测试项目
        ProjectItem *project1 = m_projectListModel->createNewProject();
        ProjectItem *project2 = m_projectListModel->createNewProject();
        
        // 更新视图
        m_galleryView->onProjectAdded(*project1);
        m_galleryView->onProjectAdded(*project2);
    }
}
