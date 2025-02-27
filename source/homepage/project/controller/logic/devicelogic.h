#ifndef DEVICELOGIC_H
#define DEVICELOGIC_H

#include <QObject>
#include "global_h.h"

class DeviceListModel;
class DeviceGalleryView;
class DeviceInfo;
class ProjectItem;

// 设备逻辑控制器 - 处理设备相关的业务逻辑
class PROJECT_EXPORT DeviceLogic : public QObject
{
    Q_OBJECT
public:
    explicit DeviceLogic(QObject *parent = nullptr);

    // 设置依赖的模型和视图
    void setDeviceListModel(DeviceListModel *model);
    void setDeviceGalleryView(DeviceGalleryView *view);
    void setCurrentProject(const ProjectItem &project);

    // 加载项目中的设备
    void loadDevicesForProject(const ProjectItem &project);

public slots:
    // 业务逻辑槽函数
    void createNewDevice();
    void openDevice(const DeviceInfo &device);
    void deleteDevice(const DeviceInfo &device);
    void backToProjects(); // 返回项目列表
    void showDeviceDetails(const DeviceInfo &device); // 显示设备详情

signals:
    // 发送给其他组件的信号
    void deviceOpened(const DeviceInfo &device);
    void returnToProjects();
    void deviceCreated(const DeviceInfo &device);
    void deviceDeleted(const DeviceInfo &device);

private:
    DeviceListModel *m_deviceListModel;
    DeviceGalleryView *m_deviceGalleryView;
    ProjectItem *m_currentProject;
};

#endif // DEVICELOGIC_H
