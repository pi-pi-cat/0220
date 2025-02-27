#include "devicegalleryview.h"
#include <QDebug>


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
    // 创建新的设备卡片
    DeviceCard *card = new DeviceCard(device, m_area);

    // 连接卡片信号
    connect(card, &DeviceCard::cardClicked, this, [this, device]() {
        emit deviceCardClicked(device);
    });

    connect(card, &DeviceCard::deleteClicked, this, [this, device]() {
        emit deviceCardDelete(device);
    });

    connect(card, &DeviceCard::editClicked, this, [this, device]() {
        // 可以添加编辑设备信号
        emit deviceCardClicked(device); // 暂时使用点击信号
    });

    connect(card, &DeviceCard::copyClicked, this, [this, device]() {
        // 可以添加复制设备功能
        qDebug() << "复制设备:" << device.displayName();
    });

    // 添加到布局
    addDeviceCard(card);
}

void DeviceGalleryView::onDeviceRemoved(const DeviceInfo &device)
{
    for (int i = 0; i < m_flowLayout->count(); ++i) {
        DeviceCard *card = qobject_cast<DeviceCard*>(m_flowLayout->itemAt(i)->widget());
        if (card && card->getDeviceInfo().name() == device.name()) {
            // 从布局中移除
            QLayoutItem *item = m_flowLayout->takeAt(i);
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;

            // 更新布局
            m_flowLayout->invalidate();
            m_area->updateGeometry();
            m_area->layout()->activate();
            break;
        }
    }
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
