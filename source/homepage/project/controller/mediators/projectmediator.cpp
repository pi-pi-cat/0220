#include "projectmediator.h"

#include "../../views/components/projectcard/projectcard.h"
#include "../../views/composites/projectgallery/projectgalleryview.h"
#include "../../models/datamodel/projectlistmodel.h"
#include "../../controller/logic/projectlogic.h"

ProjectMediator::ProjectMediator(QObject *parent) : QObject(parent),
    m_galleryView(nullptr),
    m_projectLogic(nullptr),
    m_projectListModel(nullptr)
{

}

void ProjectMediator::initialize(ProjectGalleryView *galleryView, ProjectLogic *projectLogic, ProjectListModel *projectListModel)
{
    m_galleryView = galleryView;
    m_projectLogic = projectLogic;
    m_projectListModel = projectListModel;

    connectSignals();
}

void ProjectMediator::connectSignals()
{
    if (!m_galleryView || !m_projectLogic || !m_projectListModel) {
        qDebug() << "错误：未初始化组件，无法连接信号";
        return;
    }

    ProjectCard *card = m_galleryView->m_addCard;
    if(card){
        connect(card, &ProjectCard::cardCreate, m_projectLogic, &ProjectLogic::createNewProject);
    }

    // // 连接普通卡片的点击信号
    // connect(m_galleryView, &GalleryView::projectCardClicked, this, [this](const ProjectItem& project) {
    //     // TODO: 处理项目卡片点击事件
    //     qDebug() << "Project clicked:" << project.name();
    // });
    // 连接普通卡片的点击信号
    connect(m_galleryView, &ProjectGalleryView::projectCardClicked,
            m_projectLogic, &ProjectLogic::openProject);
    // 连接普通卡片的删除信号
    connect(m_galleryView, &ProjectGalleryView::projectCardDelete,
            m_projectLogic, &ProjectLogic::deleteProject);
    // Connect new project button
    connect(m_galleryView, &ProjectGalleryView::newProjectClicked,
            m_projectLogic, &ProjectLogic::createNewProject);

    // Connect open project button
    connect(m_galleryView, &ProjectGalleryView::openProjectClicked,
            this, &ProjectMediator::handleOpenProject);

    // Connect sort combo box
    connect(m_galleryView, &ProjectGalleryView::sortOrderChanged,
            this, &ProjectMediator::handleSortOrderChanged);

    // Connect search text changes
    connect(m_galleryView, &ProjectGalleryView::searchTextChanged,
            this, &ProjectMediator::handleSearchTextChanged);
}


void ProjectMediator::handleOpenProject()
{
    // Implement open project dialog logic
    qDebug() << "Open project dialog requested";
    // ...
}

void ProjectMediator::handleSortOrderChanged(int index)
{
    // Convert index to sort role and call project logic
    ProjectListModel::SortRole role;
    switch (index) {
    case 0: role = ProjectListModel::RecentUsed; break;
    case 1: role = ProjectListModel::ByName; break;
    case 2: role = ProjectListModel::BySize; break;
    default: role = ProjectListModel::RecentUsed;
    }

    m_projectLogic->sortProjects(role);
}

void ProjectMediator::handleSearchTextChanged(const QString &text)
{
    // Implement search filtering logic
    qDebug() << "Search text changed to:" << text;
    // ...
}
