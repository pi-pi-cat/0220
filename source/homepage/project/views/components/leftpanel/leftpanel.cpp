#include "leftpanel.h"
#include "ui_leftpanel.h"

#include <QFile>

LeftPanel::LeftPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftPanel)
{
    ui->setupUi(this);
    QFile styleFile(":styles/leftpanel.qss");
    if(styleFile.open(QFile::ReadOnly)){
        QString styleSheet = styleFile.readAll();
        ui->newProjectButton->setObjectName("newprojectButton");
        ui->newProjectButton->setStyleSheet(styleSheet);

        ui->openProjectButton->setObjectName("openprojectButton");
        ui->openProjectButton->setStyleSheet(styleSheet);
        styleFile.close();
    }
}

LeftPanel::~LeftPanel()
{
    delete ui;
}
