#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "views/composites/devicegallery/devicegalleryview.h"
#include "views/composites/projectgallery/projectgalleryview.h"
#include "controller/logic/projectlogic.h"
#include "controller/logic/devicelogic.h"
#include "controller/mediators/projectmediator.h"
#include "controller/mediators/devicemediator.h"
#include "models/datamodel/projectlistmodel.h"
#include "models/datamodel/devicelistmodel.h"
#include "models/internal/projectitem.h"
#include "models/internal/deviceinfo.h"
#include "controller/eventbus/eventbus.h"
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_currentProject(nullptr)
    , m_currentDevice(nullptr)
{
    ui->setupUi(this);

    setupUI();
    setupModels();
    setupLogic();
    setupMediators();
    setupEventBus();
    connectSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_currentProject) {
        delete m_currentProject;
    }
    if (m_currentDevice) {
        delete m_currentDevice;
    }
}

void MainWindow::setupUI()
{
    // 设置堆叠窗口管理不同视图
    m_stackedWidget = new QStackedWidget(this);
    setCentralWidget(m_stackedWidget);

    // 创建项目视图
    m_projectWidget = new QWidget(this);
    QHBoxLayout* projectLayout = new QHBoxLayout(m_projectWidget);
    projectLayout->setSpacing(0);
    projectLayout->setContentsMargins(0, 0, 0, 0);
    m_projectGalleryView = new ProjectGalleryView(this);
    projectLayout->addWidget(m_projectGalleryView);

    // 创建设备视图
    m_deviceWidget = new QWidget(this);
    QVBoxLayout* deviceLayout = new QVBoxLayout(m_deviceWidget);
    deviceLayout->setSpacing(10);
    deviceLayout->setContentsMargins(10, 10, 10, 10);

    // 添加顶部面板
    QWidget* topPanel = new QWidget(this);
    QHBoxLayout* topLayout = new QHBoxLayout(topPanel);
    topLayout->setContentsMargins(0, 0, 0, 0);

    QPushButton* backButton = new QPushButton("返回项目列表", this);
    QLabel* projectNameLabel = new QLabel("当前项目: ", this);
    projectNameLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

    topLayout->addWidget(backButton);
    topLayout->addWidget(projectNameLabel, 1);

    // 创建设备画廊视图
    m_deviceGalleryView = new DeviceGalleryView(this);

    deviceLayout->addWidget(topPanel);
    deviceLayout->addWidget(m_deviceGalleryView, 1);

    // 创建设备详情视图
    m_deviceDetailWidget = new QWidget(this);
    QVBoxLayout* detailLayout = new QVBoxLayout(m_deviceDetailWidget);

    QWidget* detailTopPanel = new QWidget(this);
    QHBoxLayout* detailTopLayout = new QHBoxLayout(detailTopPanel);

    QPushButton* backToDevicesButton = new QPushButton("返回设备列表", this);
    QLabel* deviceNameLabel = new QLabel("设备详情: ", this);
    deviceNameLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

    detailTopLayout->addWidget(backToDevicesButton);
    detailTopLayout->addWidget(deviceNameLabel, 1);

    QLabel* deviceDetailsContent = new QLabel("这里显示设备详细信息", this);
    deviceDetailsContent->setAlignment(Qt::AlignCenter);
    deviceDetailsContent->setStyleSheet("font-size: 18px; color: #666;");

    detailLayout->addWidget(detailTopPanel);
    detailLayout->addWidget(deviceDetailsContent, 1);

    // 添加窗口到堆叠窗口
    m_stackedWidget->addWidget(m_projectWidget);
    m_stackedWidget->addWidget(m_deviceWidget);
    m_stackedWidget->addWidget(m_deviceDetailWidget);

    // 开始显示项目视图
    m_stackedWidget->setCurrentWidget(m_projectWidget);

    // 连接返回按钮
    connect(backButton, &QPushButton::clicked, this, &MainWindow::onReturnToProjects);
    connect(backToDevicesButton, &QPushButton::clicked, [this]() {
        m_stackedWidget->setCurrentWidget(m_deviceWidget);
    });
}

void MainWindow::setupModels()
{
    // 创建模型
    m_projectListModel = new ProjectListModel(this);
    m_deviceListModel = new DeviceListModel(this);
}

void MainWindow::setupLogic()
{
    // 创建逻辑控制器
    m_projectLogic = new ProjectLogic(this);
    m_deviceLogic = new DeviceLogic(this);

    // 配置项目逻辑控制器
    m_projectLogic->setProjectListModel(m_projectListModel);
    m_projectLogic->setGalleryView(m_projectGalleryView);
    m_projectLogic->loadInitialProjects();

    // 配置设备逻辑控制器
    m_deviceLogic->setDeviceListModel(m_deviceListModel);
    m_deviceLogic->setDeviceGalleryView(m_deviceGalleryView);
}

void MainWindow::setupMediators()
{
    // 创建并初始化中介者
    m_projectMediator = new ProjectMediator(this);
    m_projectMediator->initialize(m_projectGalleryView, m_projectLogic, m_projectListModel);

    m_deviceMediator = new DeviceMediator(this);
    m_deviceMediator->initialize(m_deviceGalleryView, m_deviceLogic, m_deviceListModel);
}

void MainWindow::setupEventBus()
{
    // 订阅事件总线上的事件
    EventBus::getInstance().subscribe("ShowDeviceView", this, "onShowDeviceView");
    EventBus::getInstance().subscribe("ShowProjectView", this, "onShowProjectView");
    EventBus::getInstance().subscribe("ShowDeviceDetails", this, "onShowDeviceDetails");
}

void MainWindow::connectSignals()
{
    // 连接组件间的信号
    connect(m_projectLogic, &ProjectLogic::projectOpened,
            this, &MainWindow::onProjectOpened);

    connect(m_deviceLogic, &DeviceLogic::deviceOpened,
            this, &MainWindow::onDeviceOpened);

    connect(m_deviceLogic, &DeviceLogic::returnToProjects,
            this, &MainWindow::onReturnToProjects);
}

void MainWindow::onProjectOpened(const ProjectItem& project)
{
    qDebug() << "主窗口: 打开项目" << project.name();

    // 存储当前项目
    if (m_currentProject) {
        delete m_currentProject;
    }
    m_currentProject = new ProjectItem(project);

    // 加载项目的设备
    m_deviceLogic->loadDevicesForProject(project);

    // 切换到设备视图
    m_stackedWidget->setCurrentWidget(m_deviceWidget);

    // 更新设备视图标题
    QLabel* projectNameLabel = m_deviceWidget->findChild<QLabel*>();
    if (projectNameLabel) {
        projectNameLabel->setText("当前项目: " + project.name());
    }
}

void MainWindow::onDeviceOpened(const DeviceInfo& device)
{
    qDebug() << "主窗口: 打开设备" << device.displayName();

    // 存储当前设备
    if (m_currentDevice) {
        delete m_currentDevice;
    }
    m_currentDevice = new DeviceInfo(device);
}

void MainWindow::onReturnToProjects()
{
    // 返回项目视图
    m_stackedWidget->setCurrentWidget(m_projectWidget);
}

void MainWindow::onShowDeviceView(const QVariant& data)
{
    // 事件总线通知显示设备视图
    m_stackedWidget->setCurrentWidget(m_deviceWidget);
}

void MainWindow::onShowProjectView(const QVariant& data)
{
    // 事件总线通知显示项目视图
    m_stackedWidget->setCurrentWidget(m_projectWidget);
}

void MainWindow::onShowDeviceDetails(const QVariant& data)
{
    // 事件总线通知显示设备详情
    DeviceInfo device = data.value<DeviceInfo>();

    // 更新设备详情视图
    QLabel* deviceNameLabel = m_deviceDetailWidget->findChild<QLabel*>();
    if (deviceNameLabel) {
        deviceNameLabel->setText("设备详情: " + device.displayName());
    }

    // 显示设备详情视图
    m_stackedWidget->setCurrentWidget(m_deviceDetailWidget);
}
