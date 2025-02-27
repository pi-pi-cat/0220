#include "devicelogic.h"
#include "../../models/datamodel/devicelistmodel.h"
#include "../../views/composites/devicegallery/devicegalleryview.h"
#include "../../models/internal/deviceinfo.h"
#include "../../models/internal/projectitem.h"
#include "../../models/persistence/projectxmlutils.h"
#include "../eventbus/eventbus.h"

DeviceLogic::DeviceLogic(QObject *parent) : QObject(parent),
    m_deviceListModel(nullptr),
    m_deviceGalleryView(nullptr),
    m_currentProject(nullptr)
{
}

void DeviceLogic::setDeviceListModel(DeviceListModel *model)
{
    m_deviceListModel = model;
}

void DeviceLogic::setDeviceGalleryView(DeviceGalleryView *view)
{
    m_deviceGalleryView = view;
}

void DeviceLogic::setCurrentProject(const ProjectItem &project)
{
    if (m_currentProject) {
        delete m_currentProject;
    }
    m_currentProject = new ProjectItem(project);
}

void DeviceLogic::createNewDevice()
{
    if (m_deviceListModel && m_currentProject) {
        // 创建新设备的默认值
        DeviceInfo newDevice;
        newDevice.setName("新设备_" + QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch()));
        newDevice.setDisplayName("新设备");
        newDevice.setCreationTime(QDateTime::currentDateTime());
        newDevice.setModificationTime(QDateTime::currentDateTime());
        newDevice.setDescription("新建设备描述");
        newDevice.setStatus("待配置");
        newDevice.setIsNewCard(true);

        // 添加到模型
        QList<DeviceInfo> devices = m_deviceListModel->getDevices();
        devices.append(newDevice);
        m_deviceListModel->setDevices(devices);

        // 更新视图
        if (m_deviceGalleryView) {
            m_deviceGalleryView->onDeviceAdded(newDevice);
        }

        emit deviceCreated(newDevice);
    }
}

void DeviceLogic::openDevice(const DeviceInfo &device)
{
    // 处理打开设备
    qDebug() << "打开设备:" << device.displayName();

    // 发送信号给其他组件
    emit deviceOpened(device);
}

void DeviceLogic::deleteDevice(const DeviceInfo &device)
{
    if (m_deviceListModel) {
        // 从模型中移除
        QList<DeviceInfo> devices = m_deviceListModel->getDevices();
        for (int i = 0; i < devices.size(); i++) {
            if (devices[i].name() == device.name()) {
                devices.removeAt(i);
                break;
            }
        }
        m_deviceListModel->setDevices(devices);

        // 更新视图
        if (m_deviceGalleryView) {
            m_deviceGalleryView->onDeviceRemoved(device);
        }

        emit deviceDeleted(device);
    }
}

void DeviceLogic::backToProjects()
{
    // 返回项目列表
    emit returnToProjects();

    // 通过事件总线发布返回项目列表的消息
    EventBus::getInstance().publish("BackToProjects");
}

void DeviceLogic::showDeviceDetails(const DeviceInfo &device)
{
    // 显示设备详情的逻辑
    qDebug() << "显示设备详情:" << device.displayName();

    // 可以通过事件总线发布消息
    QVariant data;
    data.setValue(device);
    EventBus::getInstance().publish("ShowDeviceDetails", data);
}

void DeviceLogic::loadDevicesForProject(const ProjectItem &project)
{
    // 设置当前项目
    setCurrentProject(project);

    // 从XML获取设备列表
    if (m_deviceListModel) {
        QList<DeviceInfo> devices = ProjectXmlUtils::parseDevices(project.path());
        m_deviceListModel->setDevices(devices);

        // 更新视图
        if (m_deviceGalleryView) {
            m_deviceGalleryView->clear();
            for (const DeviceInfo &device : devices) {
                m_deviceGalleryView->onDeviceAdded(device);
            }
        }
    }
}
