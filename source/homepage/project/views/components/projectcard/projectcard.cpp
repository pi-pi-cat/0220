#include "projectcard.h"
#include "../../../models/internal/projectitem.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QStyle>
#include <QFile>

ProjectCard::ProjectCard(QWidget *parent) :
    QWidget(parent),
    m_projectNameLabel(nullptr),
    m_projectPathLabel(nullptr),
    m_lastModifiedLabel(nullptr),
    m_editButton(nullptr),
    m_deleteButton(nullptr),
    m_mainWidget(nullptr),
    m_imageContainer(nullptr),
    m_imageLabels{nullptr, nullptr, nullptr, nullptr},
    m_isCreateCard(true)
{
    setAttribute(Qt::WA_Hover);
    setAutoFillBackground(true);
    setupUi();
    setupPlusIcon();
}

ProjectCard::ProjectCard(const ProjectItem &item, QWidget *parent):
    QWidget(parent),
    m_projectNameLabel(nullptr),
    m_projectPathLabel(nullptr),
    m_lastModifiedLabel(nullptr),
    m_editButton(nullptr),
    m_deleteButton(nullptr),
    m_mainWidget(nullptr),
    m_imageContainer(nullptr),
    m_imageLabels{nullptr, nullptr, nullptr, nullptr},
    m_plusIcon(nullptr),
    m_isCreateCard(false)
{
    setAttribute(Qt::WA_Hover);
    setAutoFillBackground(true);
    setupUi();

    // Set data
    m_projectNameLabel->setText(item.name());
    m_projectPathLabel->setText(item.path());
    m_lastModifiedLabel->setText(item.lastEditTime().toString("yyyy-MM-dd hh:mm:ss"));
}

ProjectCard::~ProjectCard()
{
    // Qt will automatically delete all child widgets
}

void ProjectCard::setupUi()
{
    // Set fixed size for the card
    setFixedSize(500, 382);

    // Main vertical layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // Main widget
    m_mainWidget = new QWidget(this);
    m_mainWidget->setObjectName("mainWidget");
    m_mainWidget->setFixedSize(474, 358);

    // Main widget layout
    QVBoxLayout *verticalLayout = new QVBoxLayout(m_mainWidget);

    // Image container widget
    m_imageContainer = new QWidget(m_mainWidget);
    m_imageContainer->setObjectName("imageContainer");
    m_imageContainer->setFixedSize(450, 250);

    // Grid layout for image container
    QGridLayout *gridLayout = new QGridLayout(m_imageContainer);
    gridLayout->setContentsMargins(10, 10, 10, 10);
    gridLayout->setSpacing(0);

    // Create four image labels and add them to the grid
    for (int i = 0; i < 4; i++) {
        int row = i / 2;
        int col = i % 2;

        m_imageLabels[i] = new QLabel(m_imageContainer);
        m_imageLabels[i]->setObjectName(QString("imageLabel%1").arg(i+1));
        m_imageLabels[i]->setFixedSize(200, 100);
        m_imageLabels[i]->setStyleSheet("background-color: #a0f0f0; border-radius: 10px;");

        gridLayout->addWidget(m_imageLabels[i], row, col);
    }

    // Add image container to main layout
    verticalLayout->addWidget(m_imageContainer);

    // Create horizontal layout for name and buttons
    QHBoxLayout *horizontalLayout = new QHBoxLayout();

    // Project name label
    m_projectNameLabel = new QLabel(m_mainWidget);
    m_projectNameLabel->setObjectName("projectNameLabel");
    QFont nameFont = m_projectNameLabel->font();
    nameFont.setPointSize(11);
    nameFont.setBold(true);
    m_projectNameLabel->setFont(nameFont);
    m_projectNameLabel->setText(m_isCreateCard ? "新建工程" : "");
    m_projectNameLabel->setIndent(10);

    // Edit button
    m_editButton = new QPushButton(m_mainWidget);
    m_editButton->setObjectName("editButton");
    m_editButton->setFixedSize(24, 24);
    m_editButton->setToolTip("编辑");
    m_editButton->setStyleSheet("border: none;");
    m_editButton->setText("E");
    m_editButton->setFlat(true);

    // Delete button
    m_deleteButton = new QPushButton(m_mainWidget);
    m_deleteButton->setObjectName("deleteButton");
    m_deleteButton->setFixedSize(24, 24);
    m_deleteButton->setToolTip("删除");
    m_deleteButton->setStyleSheet("border: none;");
    m_deleteButton->setText("D");
    m_deleteButton->setFlat(true);

    // Connect delete button signal
    connect(m_deleteButton, &QPushButton::clicked, this, &ProjectCard::on_deleteButton_clicked);

    // Add widgets to horizontal layout
    horizontalLayout->addWidget(m_projectNameLabel);
    horizontalLayout->addWidget(m_editButton);
    horizontalLayout->addWidget(m_deleteButton);

    verticalLayout->addLayout(horizontalLayout);

    // Project path label
    m_projectPathLabel = new QLabel(m_mainWidget);
    m_projectPathLabel->setObjectName("projectPathLabel");
    QFont pathFont = m_projectPathLabel->font();
    pathFont.setPointSize(9);
    m_projectPathLabel->setFont(pathFont);
    m_projectPathLabel->setStyleSheet("color: #666666;");
    m_projectPathLabel->setWordWrap(true);
    m_projectPathLabel->setIndent(10);

    verticalLayout->addWidget(m_projectPathLabel);

    // Last modified label
    m_lastModifiedLabel = new QLabel(m_mainWidget);
    m_lastModifiedLabel->setObjectName("lastModifiedLabel");
    QFont modifiedFont = m_lastModifiedLabel->font();
    modifiedFont.setPointSize(9);
    m_lastModifiedLabel->setFont(modifiedFont);
    m_lastModifiedLabel->setStyleSheet("color: #666666;");
    m_lastModifiedLabel->setIndent(10);

    verticalLayout->addWidget(m_lastModifiedLabel);

    // Add main widget to main layout
    mainLayout->addWidget(m_mainWidget);

    // Load stylesheet
    loadStyleSheet();
}

void ProjectCard::loadStyleSheet()
{
    // Load styles from QSS file
    QFile file(":/styles/projectcard.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
        file.close();
    }
}

void ProjectCard::setIsCreateCard(bool isCreate)
{
    m_isCreateCard = isCreate;
    if (m_projectNameLabel) {
        m_projectNameLabel->setText(isCreate ? "新建工程" : m_projectNameLabel->text());
    }
}

bool ProjectCard::isCreateCard() const
{
    return m_isCreateCard;
}

QString ProjectCard::projectPath() const
{
    return m_projectPathLabel ? m_projectPathLabel->text() : QString();
}

QString ProjectCard::projectName() const
{
    return m_projectNameLabel ? m_projectNameLabel->text() : QString();
}

QString ProjectCard::uniqueId() const
{
    return m_projectNameLabel ? m_projectNameLabel->text() : QString();
}

bool ProjectCard::event(QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        // Mouse enter handling
        if (m_plusIcon) {
            updatePlusIconPosition();
            m_plusIcon->show(); // Show plus icon on hover
        }
        return true;
    }
    else if (event->type() == QEvent::Leave) {
        if (m_plusIcon) {
            m_plusIcon->hide(); // Hide plus icon when not hovering
        }
        return true;
    }
    else if (event->type() == QEvent::MouseButtonPress) {
        // Mouse click handling
        if (m_isCreateCard) {
            emit cardCreate();
        } else {
            emit cardClicked();
        }
        return true;
    }

    // Let the parent class handle other events
    return QWidget::event(event);
}


void ProjectCard::setupPlusIcon()
{
    m_plusIcon = new QLabel(m_imageContainer);

    // 设置加号文本和样式
    m_plusIcon->setFixedSize(40, 40); // 设置固定的宽度和高度（例如80px）
    m_plusIcon->setObjectName("plusIcon");
    m_plusIcon->setText("+");

    // 初始状态隐藏
    m_plusIcon->hide();

    // 设置对齐方式
    m_plusIcon->setAlignment(Qt::AlignCenter);
}

void ProjectCard::updatePlusIconPosition()
{
    if (m_plusIcon && m_imageContainer) {
        // 获取加号标签的建议大小
        QSize iconSize = m_plusIcon->sizeHint();

        // 计算居中位置
        int x = (m_imageContainer->width() - iconSize.width()) / 2;
        int y = (m_imageContainer->height() - iconSize.height()) / 2;

        // 设置加号位置和大小
        m_plusIcon->setGeometry(x, y, iconSize.width(), iconSize.height());
    }
}

void ProjectCard::on_deleteButton_clicked()
{
    emit cardDelete();
}
