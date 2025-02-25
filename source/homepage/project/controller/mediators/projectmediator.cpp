#include "projectmediator.h"

#include "../../views/components/projectcard/projectcard.h"
#include "../../views/composites/galleryview/galleryview.h"
#include "../../models/datamodel/projectlistmodel.h"
#include "../../controller/logic/projectlogic.h"

ProjectMediator::ProjectMediator(QObject *parent) : QObject(parent),
    m_galleryView(nullptr),
    m_projectLogic(nullptr),
    m_projectListModel(nullptr)
{

}

void ProjectMediator::initialize(GalleryView *galleryView, ProjectLogic *projectLogic, ProjectListModel *projectListModel)
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
}
