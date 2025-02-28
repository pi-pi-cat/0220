#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVariant>

class ProjectItem;
class DeviceInfo;
class DeviceGalleryView;
class ProjectLogic;
class DeviceLogic;
class ProjectMediator;
class DeviceMediator;
class ProjectListModel;
class DeviceListModel;
class ProjectGalleryView;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onProjectOpened(const ProjectItem& project);
    void onDeviceOpened(const DeviceInfo& device);
    void onReturnToProjects();

    // 事件总线消息处理
    void onShowDeviceView(const QVariant& data = QVariant());
    void onShowProjectView(const QVariant& data = QVariant());
    void onShowDeviceDetails(const QVariant& data);

private:
    // UI 设置
    void setupUI();
    void setupModels();
    void setupLogic();
    void setupMediators();
    void setupEventBus();
    void connectSignals();

    Ui::MainWindow *ui;

    // UI 组件
    QStackedWidget *m_stackedWidget;
    QWidget *m_projectWidget;
    QWidget *m_deviceWidget;
    QWidget *m_deviceDetailWidget;
    ProjectGalleryView *m_projectGalleryView;
    DeviceGalleryView *m_deviceGalleryView;

    // 模型
    ProjectListModel *m_projectListModel;
    DeviceListModel *m_deviceListModel;

    // 逻辑控制器
    ProjectLogic *m_projectLogic;
    DeviceLogic *m_deviceLogic;

    // 中介者
    ProjectMediator *m_projectMediator;
    DeviceMediator *m_deviceMediator;

    // 当前数据
    ProjectItem *m_currentProject;
    DeviceInfo *m_currentDevice;
};
#endif // MAINWINDOW_H
