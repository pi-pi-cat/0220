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
//    setStyleSheet("QWidget { background-color: #a0a0a0; } QPushButton { background-color: #a0a0a0;  border: none; }");
    setStyleSheet("background-color: #a0a0a0; ");
    qDebug() << "移入";
    updatePlusIconPosition();
    m_plusIcon->show(); // 显示加号
    QWidget::enterEvent(event);
}

void ProjectCard::leaveEvent(QEvent *event)
{
    setStyleSheet("background-color: transparent;"); // 恢复透明
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
    m_plusIcon->setText("+");
    m_plusIcon->setStyleSheet(
        "QLabel {"
        "   color: white;"
        "   font-size: 100px;"
        "   font-weight: bold;"
        "   background-color: transparent;"
        "}"
        );

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
