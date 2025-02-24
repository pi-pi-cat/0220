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

}

MainWindow::~MainWindow()
{
    delete ui;
}
