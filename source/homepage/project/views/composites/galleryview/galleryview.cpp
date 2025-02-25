#include "galleryview.h"
#include "ui_galleryview.h"


GalleryView::GalleryView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GalleryView)
{
    ui->setupUi(this);
    m_flowLayout = new FlowLayout(ui->scrollAreaWidgetContents, 10, 10, 10);

    // 删除原有的垂直布局（如果存在）
    if (ui->scrollAreaWidgetContents->layout()) {
        delete ui->scrollAreaWidgetContents->layout();
    }

    // 设置布局
    ui->scrollAreaWidgetContents->setLayout(m_flowLayout);

    // 添加新增卡片选项
    m_addCard = new ProjectCard(ui->scrollAreaWidgetContents);
    addProjectCard(m_addCard);
}

GalleryView::~GalleryView()
{
    delete ui;
}

void GalleryView::addProjectCard(ProjectCard *card)
{
    if (card) {
        // 如果是添加普通项目卡片，需要将其插入到新建卡片之前
        if (!card->isCreateCard()) {
            int lastIndex = m_flowLayout->count() - 1;
            m_flowLayout->insertWidget(lastIndex, card);
        } else {
            m_flowLayout->addWidget(card);
        }
        ui->scrollAreaWidgetContents->updateGeometry();
    }
}

void GalleryView::onProjectAdded(const ProjectItem &project)
{
    // 1. 创建新的项目卡片
    ProjectCard *card = new ProjectCard(project, ui->scrollAreaWidgetContents);

    // 2. 连接卡片的点击信号
    connect(card, &ProjectCard::cardClicked, this, [this, project]() {
        emit projectCardClicked(project);
    });
    connect(card, &ProjectCard::cardDelete, this, [this, project](){
        emit projectCardDelete(project);
    });

    // 3. 添加到布局中，确保在"新建"卡片之前
    addProjectCard(card);
}

void GalleryView::onProjectRemoved(const ProjectItem &project)
{
    for (int i = 0; i < m_flowLayout->count(); ++i){
        ProjectCard *card = qobject_cast<ProjectCard*>(m_flowLayout->itemAt(i)->widget());
        if(card && !card->isCreateCard() && card->projectName() == project.name() && card->projectPath() == project.path()){
            // 从布局中移除
            QLayoutItem *item = m_flowLayout->takeAt(i);
            if (item->widget()){
                item->widget()->deleteLater(); // 安全删除 widget
            }
            delete item; // 删除布局项

            // 更新布局 (前两句是为了触发布局更新，强制重新计算)
            m_flowLayout->invalidate();
            ui->scrollAreaWidgetContents->updateGeometry();
            ui->scrollAreaWidgetContents->layout()->activate();
            break;
        }
    }
}

void GalleryView::sortCards(const QList<ProjectItem> &sortedProjects)
{
    // 创建一个映射，存储卡片和它们的新位置
    QMap<QString, int> newPositions;
    QMap<QString, ProjectCard*> cardMap;
    ProjectCard *createCard = nullptr;

    // 第一步：查找所有现有卡片，并将"新建"卡片单独保存
    for (int i = 0; i < m_flowLayout->count(); ++i) {
        ProjectCard *card = qobject_cast<ProjectCard*>(m_flowLayout->itemAt(i)->widget());
        if (card) {
            if (card->isCreateCard()) {
                createCard = card;
            } else {
                cardMap[card->uniqueId()] = card;
            }
        }
    }

    // 第二步：清空布局（但不删除卡片）
    while (m_flowLayout->count() > 0) {
        m_flowLayout->takeAt(0);
    }

    // 第三步：按照排序后的顺序添加卡片
    for (int i = 0; i < sortedProjects.size(); ++i) {
        QString uniqueId = sortedProjects[i].path();
        if (cardMap.contains(uniqueId)) {
            m_flowLayout->addWidget(cardMap[uniqueId]);
            cardMap.remove(uniqueId); // 从映射中移除已添加的卡片
        } else {
            // 如果没有找到对应的卡片，创建一个新的
            ProjectCard *newCard = new ProjectCard(sortedProjects[i], ui->scrollAreaWidgetContents);
            connect(newCard, &ProjectCard::cardClicked, this,
                [this, i, sortedProjects]() {
                    emit projectCardClicked(sortedProjects[i]);
                });
            connect(newCard, &ProjectCard::cardDelete, this,
                [this, i, sortedProjects]() {
                    emit projectCardDelete(sortedProjects[i]);
                });
            m_flowLayout->addWidget(newCard);
        }
    }

    // 第四步：添加"新建"卡片（如果有）
    if (createCard) {
        m_flowLayout->addWidget(createCard);
    }

    // 第五步：删除未使用的卡片
    for (auto card : cardMap.values()) {
        card->deleteLater();
    }

    // 更新布局
    ui->scrollAreaWidgetContents->updateGeometry();
}

void GalleryView::clear()
{
    QLayoutItem *item;
    while ((item = m_flowLayout->takeAt(0))) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }
}
