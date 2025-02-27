#include "devicemediator.h"
#include "../../views/components/devicecard/devicecard.h"
#include "../../views/composites/devicegallery/devicegalleryview.h"
#include "../../models/datamodel/devicelistmodel.h"
#include "../../controller/logic/devicelogic.h"
#include "../../models/internal/projectitem.h"
#include "../eventbus/eventbus.h"

DeviceMediator::DeviceMediator(QObject *parent) : QObject(parent),
    m_deviceGalleryView(nullptr),
    m_deviceLogic(nullptr),
    m_deviceListModel(nullptr),
    m_currentProject(nullptr)
{
    // 订阅事件总线上的事件
    EventBus::getInstance().subscribe("OpenDeviceView", this, "onOpenDeviceView");
    EventBus::getInstance().subscribe("BackToProjects", this, "onBackToProjects");
}

void DeviceMediator::initialize(DeviceGalleryView *deviceGalleryView,
                                DeviceLogic *deviceLogic,
                                DeviceListModel *deviceListModel)
{
    m_deviceGalleryView = deviceGalleryView;
    m_deviceLogic = deviceLogic;
    m_deviceListModel = deviceListModel;

    connectSignals();
}

void DeviceMediator::connectSignals()
{
    if (!m_deviceGalleryView || !m_deviceLogic || !m_deviceListModel) {
        qDebug() << "错误：未初始化组件，无法连接信号";
        return;
    }

    // 连接"新建设备"卡片的信号
    NewDeviceCard *card = m_deviceGalleryView->m_addCard;
    if (card) {
        connect(card, &NewDeviceCard::createNewDevice, m_deviceLogic, &DeviceLogic::createNewDevice);
    }

    // 连接设备卡片的信号
    connect(m_deviceGalleryView, &DeviceGalleryView::deviceCardClicked,
            m_deviceLogic, &DeviceLogic::openDevice);
    connect(m_deviceLogic, &DeviceLogic::deviceOpened,
            m_deviceLogic, &DeviceLogic::showDeviceDetails);
    connect(m_deviceGalleryView, &DeviceGalleryView::deviceCardDelete,
            m_deviceLogic, &DeviceLogic::deleteDevice);
}

void DeviceMediator::loadDevicesForProject(const ProjectItem &project)
{
    // 存储当前项目
    if (m_currentProject) {
        delete m_currentProject;
    }
    m_currentProject = new ProjectItem(project);

    // 加载设备
    m_deviceLogic->loadDevicesForProject(project);
}

void DeviceMediator::onOpenDeviceView(const QVariant &data)
{
    // 从事件总线接收到打开设备视图的消息
    ProjectItem project = data.value<ProjectItem>();
    qDebug() << "DeviceMediator: 打开项目的设备视图:" << project.name();

    // 加载设备
    loadDevicesForProject(project);

    // 通知主窗口显示设备视图
    EventBus::getInstance().publish("ShowDeviceView");
}

void DeviceMediator::onBackToProjects()
{
    // 从事件总线接收到返回项目列表的消息
    EventBus::getInstance().publish("ShowProjectView");
}
