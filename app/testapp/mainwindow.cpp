#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "views/components/leftpanel/leftpanel.h"
#include "views/composites/galleryview/galleryview.h"
#include "controller/logic/projectlogic.h"
#include "controller/mediators/projectmediator.h"
#include "models/datamodel/projectlistmodel.h"
#include "models/internal/projectitem.h"
#include <QLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建组件
    ProjectListModel *projectListModel = new ProjectListModel(this);
    ProjectLogic *projectLogic = new ProjectLogic(this);

    // 创建主窗口的中心部件
    QHBoxLayout* mainLayout = new QHBoxLayout(ui->centralwidget);
    mainLayout->setSpacing(0);  // 移除组件之间的间距
    mainLayout->setContentsMargins(0, 0, 0, 0);  // 移除布局边距

    // 创建左侧面板
    LeftPanel* leftPanel = new LeftPanel(this);
    leftPanel->setFixedWidth(150);  // 设置固定宽度
    leftPanel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);  // 水平方向固定大小

    // 创建右侧画廊视图
    GalleryView* galleryView = new GalleryView(this);
    galleryView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);  // 水平方向扩展

    // 将部件添加到布局中
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(galleryView);

    // 设置逻辑层对模型和视图的引用
    projectLogic->setProjectListModel(projectListModel);
    projectLogic->setGalleryView(galleryView);
    projectLogic->loadInitialProjects();

    // 连接项目打开信号
    connect(projectLogic, &ProjectLogic::projectOpened, this, &MainWindow::onProjectOpened);

    // 创建并初始化中介者
    ProjectMediator *projectMediator = new ProjectMediator(this);
    projectMediator->initialize(galleryView, projectLogic, projectListModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onProjectOpened(const ProjectItem &project)
{
    qDebug() << "主函数打开新窗口";
}

