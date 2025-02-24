#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "views/components/leftpanel/leftpanel.h"
#include "views/composites/galleryview/galleryview.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建主窗口的中心部件
    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setSpacing(0);  // 移除组件之间的间距
    mainLayout->setContentsMargins(0, 0, 0, 0);  // 移除布局边距

    // 创建左侧面板
    LeftPanel* leftPanel = new LeftPanel(centralWidget);
    leftPanel->setFixedWidth(250);  // 设置固定宽度
    leftPanel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);  // 水平方向固定大小

    // 创建右侧画廊视图
    GalleryView* galleryView = new GalleryView(centralWidget);
    galleryView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);  // 水平方向扩展

    // 将部件添加到布局中
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(galleryView);

    // 设置中心部件
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
