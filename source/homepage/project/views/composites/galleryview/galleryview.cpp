#include "galleryview.h"
#include "ui_galleryview.h"
#include "../../components/projectcard/projectcard.h"

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

    // 添加5个默认的测试卡片
    for (int i = 0; i < 5; i++) {
        ProjectCard *card = new ProjectCard(ui->scrollAreaWidgetContents);
        card->setMinimumSize(460, 320);  // 设置卡片的最小尺寸
        card->setMaximumSize(460, 320);  // 设置卡片的最大尺寸
        //card->setStyleSheet("background-color: #a0a0a0; border-radius: 10px;");  // 添加一些基本样式
        card->setStyleSheet("border-radius: 10px;");  // 添加一些基本样式
        addProjectCard(card);
    }
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
