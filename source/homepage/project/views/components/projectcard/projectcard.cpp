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
    setupPlusIcon();
}

ProjectCard::~ProjectCard()
{
    delete ui;
}

void ProjectCard::enterEvent(QEvent *event)
{
    ui->mainWidget->setStyleSheet("QWidget#mainWidget {border: 1px solid; background-color: #a6c1d4; border-radius: 10px;}");
    qDebug() << "移入";
    updatePlusIconPosition();
    m_plusIcon->show(); // 显示加号
    QWidget::enterEvent(event);
}

void ProjectCard::leaveEvent(QEvent *event)
{
    ui->mainWidget->setStyleSheet("QWidget#mainWidget {border: 1px solid; background-color: #f7faff; border-radius: 10px;}");// 恢复
    qDebug() << "移出";
    m_plusIcon->hide(); // 隐藏加号
    QWidget::leaveEvent(event);
}

void ProjectCard::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "点击";
    QWidget::mousePressEvent(event);
}

void ProjectCard::setupPlusIcon()
{
    m_plusIcon = new QLabel(ui->imageContainer);

    // 设置加号文本和样式
    m_plusIcon->setFixedSize(40, 40); // 设置固定的宽度和高度（例如80px）
    m_plusIcon->setStyleSheet(
        "QLabel {"
        "   color: white;"
        "   font-size: 20px;"
        "   font-weight: bold;"
        "   background-color: #0d6baf;"
        "   border-radius: 20px;" // 半径等于宽度/高度的一半
        "   text-align: center;" // 文本居中
        "   qproperty-alignment: AlignCenter;" // 确保+号居中显示
        "}"
        );
    m_plusIcon->setText("+");

    // 初始状态隐藏
    m_plusIcon->hide();

    // 设置对齐方式
    m_plusIcon->setAlignment(Qt::AlignCenter);
}

void ProjectCard::updatePlusIconPosition()
{
    if (m_plusIcon) {
        // 获取加号标签的建议大小
        QSize iconSize = m_plusIcon->sizeHint();

        // 计算居中位置
        int x = (ui->imageContainer->width() - iconSize.width()) / 2;
        int y = (ui->imageContainer->height() - iconSize.height()) / 2;


        // 设置加号位置和大小
        m_plusIcon->setGeometry(x, y, iconSize.width(), iconSize.height());
    }
}
