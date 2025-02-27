#ifndef DEVICEMEDIATOR_H
#define DEVICEMEDIATOR_H

#include <QObject>
#include <QVariant>
#include "global_h.h"

class DeviceLogic;
class DeviceGalleryView;
class DeviceListModel;
class ProjectItem;

// 设备中介者类 - 协调设备视图、模型和逻辑之间的交互
class PROJECT_EXPORT DeviceMediator : public QObject
{
    Q_OBJECT
public:
    explicit DeviceMediator(QObject *parent = nullptr);

    // 初始化中介者
    void initialize(DeviceGalleryView *deviceGalleryView, DeviceLogic *deviceLogic,
                    DeviceListModel *deviceListModel);

    // 加载项目中的设备
    void loadDevicesForProject(const ProjectItem &project);

public slots:
    // 从事件总线接收消息的槽函数
    void onOpenDeviceView(const QVariant &data);
    void onBackToProjects();

private:
    // 连接组件间的信号和槽
    void connectSignals();

    DeviceGalleryView *m_deviceGalleryView;
    DeviceLogic *m_deviceLogic;
    DeviceListModel *m_deviceListModel;
    ProjectItem *m_currentProject;
};

#endif // DEVICEMEDIATOR_H
