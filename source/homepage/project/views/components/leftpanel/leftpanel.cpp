#include "leftpanel.h"
#include "ui_leftpanel.h"

LeftPanel::LeftPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftPanel)
{
    ui->setupUi(this);
}

LeftPanel::~LeftPanel()
{
    delete ui;
}
