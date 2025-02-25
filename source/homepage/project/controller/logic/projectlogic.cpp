#include "projectlogic.h"

ProjectLogic::ProjectLogic(QObject *parent) : QObject(parent)
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

}
