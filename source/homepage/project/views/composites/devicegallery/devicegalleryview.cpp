#include "devicegalleryview.h"


DeviceGalleryView::DeviceGalleryView(QWidget *parent) : QWidget(parent)
{
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setWidgetResizable(true);  // 关键设置

    // 创建内容容器
    m_area = new QWidget;
    m_flowLayout = new FlowLayout(m_area, 10, 10, 10);
    m_area->setLayout(m_flowLayout);

    m_scrollArea->setWidget(m_area);  // 将内容部件关联到滚动区域

    // 设置DeviceGalleryView的主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this); // <- 新增
    mainLayout->addWidget(m_scrollArea);             // <- 新增
    setLayout(mainLayout);                           // <- 新增

    // 添加"新增"卡片
    m_addCard = new NewDeviceCard(m_area);
    addNewDeviceCard(m_addCard);
}

void DeviceGalleryView::addDeviceCard(DeviceCard *card)
{
    if (card) {
        int lastIndex = m_flowLayout->count() - 1; //TODO 检查索引是否越界
        m_flowLayout->insertWidget(lastIndex, card);
        m_area->updateGeometry();
    }
}

void DeviceGalleryView::addNewDeviceCard(NewDeviceCard *card)
{
    if (card) {
        m_flowLayout->addWidget(card);
        m_area->updateGeometry();
    }
}

void DeviceGalleryView::onDeviceAdded(const DeviceInfo &device)
{
    // 1. 创建新的项目卡片
    DeviceCard *card = new DeviceCard(device, m_area);

    // 2. 连接卡片的点击信号
//    connect(card, &ProjectCard::cardClicked, this, [this, project]() {
//        emit projectCardClicked(project);
//    });
//    connect(card, &ProjectCard::cardDelete, this, [this, project](){
//        emit projectCardDelete(project);
//    });

    // 3. 添加到布局中，确保在"新建"卡片之前
    addDeviceCard(card);
}

void DeviceGalleryView::onDeviceRemoved(const DeviceInfo &device)
{

}

void DeviceGalleryView::clear()
{
    QLayoutItem *item;
    while ((item = m_flowLayout->takeAt(0))) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }
}
