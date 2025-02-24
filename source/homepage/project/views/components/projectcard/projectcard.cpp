#include "projectcard.h"
#include "ui_projectcard.h"

#include <QDebug>

ProjectCard::ProjectCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectCard)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_Hover);
    setAutoFillBackground(true);

}

ProjectCard::~ProjectCard()
{
    delete ui;
}

void ProjectCard::enterEvent(QEvent *event)
{
    setStyleSheet("background-color: #a0a0a0;"); // 悬停颜色
    qDebug() << "移入";
    QWidget::enterEvent(event);
}

void ProjectCard::leaveEvent(QEvent *event)
{
    setStyleSheet("background-color: transparent;"); // 恢复透明
    qDebug() << "移出";
    QWidget::leaveEvent(event);
}

void ProjectCard::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "点击";
    QWidget::mousePressEvent(event);
}
