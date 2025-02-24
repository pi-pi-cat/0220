#include "searchtoolbar.h"
#include "ui_searchtoolbar.h"
#include <QHBoxLayout>

SearchToolBar::SearchToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchToolBar)
{
    ui->setupUi(this);
}

SearchToolBar::~SearchToolBar()
{
    delete ui;
}
