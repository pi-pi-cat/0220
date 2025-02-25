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

void GalleryView::addProjectCard(QWidget *card)
{
    if (card) {
        m_flowLayout->addWidget(card);
        ui->scrollAreaWidgetContents->updateGeometry();
    }
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
