#include "devicecard.h"
#include "../../../models/internal/deviceinfo.h"
#include <QPixmap>
#include <QEnterEvent>
#include <QStyle>

DeviceCard::DeviceCard(QWidget *parent, int width, int height)
    : QWidget(parent), m_width(width), m_height(height)
{
    setFixedSize(width, height);
    setupUI();
    setupConnections();
}

DeviceCard::DeviceCard(const DeviceInfo& info, QWidget *parent, int width, int height)
    : QWidget(parent), m_width(width), m_height(height)
{
    setFixedSize(width, height);
    setupUI();
    setupConnections();
    updateInfo(info);
}

QString DeviceCard::deviceName() const
{
    return m_nameLabel->text();
}

void DeviceCard::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Container widget that will have the styling
    m_containerWidget = new QWidget(this);
    m_containerWidget->setObjectName("containerWidget");
    m_containerWidget->setFixedSize(m_width, m_height);

    QVBoxLayout *containerLayout = new QVBoxLayout(m_containerWidget);
    containerLayout->setContentsMargins(10, 10, 10, 10);
    containerLayout->setSpacing(10);

    // Header with name and buttons
    QWidget *headerWidget = new QWidget(m_containerWidget);
    QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
    headerLayout->setContentsMargins(0, 0, 0, 0);

    m_nameLabel = new QLabel(m_containerWidget);
    m_nameLabel->setObjectName("nameLabel");

    m_copyButton = new QPushButton("复制", m_containerWidget);
    m_copyButton->setObjectName("copyButton");
    m_copyButton->setFixedSize(50, 25);

    m_editButton = new QPushButton("编辑", m_containerWidget);
    m_editButton->setObjectName("editButton");
    m_editButton->setFixedSize(50, 25);

    m_deleteButton = new QPushButton("删除", m_containerWidget);
    m_deleteButton->setObjectName("deleteButton");
    m_deleteButton->setFixedSize(50, 25);

    headerLayout->addWidget(m_nameLabel, 1);
    headerLayout->addWidget(m_copyButton);
    headerLayout->addWidget(m_editButton);
    headerLayout->addWidget(m_deleteButton);

    // Image area with frame for rounded corners
    m_imageFrame = new QFrame(m_containerWidget);
    m_imageFrame->setObjectName("imageFrame");
    m_imageFrame->setFrameShape(QFrame::NoFrame);
    m_imageFrame->setStyleSheet("background-color: white; border: 1px solid #306d9a; border-radius: 10px;");

    QVBoxLayout *imageLayout = new QVBoxLayout(m_imageFrame);
//    imageLayout->setContentsMargins(0, 0, 0, 0);

    m_imageLabel = new QLabel(m_imageFrame);
    m_imageLabel->setObjectName("imageLabel");
    m_imageLabel->setScaledContents(true);
    m_imageLabel->setAlignment(Qt::AlignCenter);
    m_imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_imageLabel->setStyleSheet("border: none; background: transparent;");

    imageLayout->addWidget(m_imageLabel);

    // Footer with timestamps
    QWidget *footerWidget = new QWidget(m_containerWidget);
    QVBoxLayout *footerLayout = new QVBoxLayout(footerWidget);
    footerLayout->setContentsMargins(0, 0, 0, 0);
    footerLayout->setSpacing(5);

    m_creationTimeLabel = new QLabel(m_containerWidget);
    m_creationTimeLabel->setObjectName("creationTimeLabel");

    m_modificationTimeLabel = new QLabel(m_containerWidget);
    m_modificationTimeLabel->setObjectName("modificationTimeLabel");

    footerLayout->addWidget(m_creationTimeLabel);
    footerLayout->addWidget(m_modificationTimeLabel);

    // Add all widgets to container
    containerLayout->addWidget(headerWidget);
    containerLayout->addWidget(m_imageFrame, 1);
    containerLayout->addWidget(footerWidget);

    mainLayout->addWidget(m_containerWidget);

    // Apply stylesheet
    // Load stylesheet
    loadStyleSheet();
}

void DeviceCard::loadStyleSheet()
{
    // Load styles from QSS file
    QFile file(":/styles/devicecard.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
        file.close();
    }
}

void DeviceCard::setupConnections()
{
    connect(m_copyButton, &QPushButton::clicked, this, &DeviceCard::copyClicked);
    connect(m_editButton, &QPushButton::clicked, this, &DeviceCard::editClicked);
    connect(m_deleteButton, &QPushButton::clicked, this, &DeviceCard::deleteClicked);
}

void DeviceCard::updateInfo(const DeviceInfo& deviceInfo)
{
    m_nameLabel->setText(deviceInfo.displayName());

    if (!deviceInfo.imagePath().isEmpty()) {
        QPixmap pixmap(deviceInfo.imagePath());
        if (!pixmap.isNull()) {
            m_imageLabel->setPixmap(pixmap);
        }
    }

    m_creationTimeLabel->setText("创建时间: " + deviceInfo.creationTime().toString("yyyy-MM-dd hh:mm:ss"));
    m_modificationTimeLabel->setText("修改时间: " + deviceInfo.modificationTime().toString("yyyy-MM-dd hh:mm:ss"));
}


bool DeviceCard::event(QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        // Change background color on hover - handled via stylesheet
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
        emit cardClicked();
        return true;
    }

    return QWidget::event(event);
}


NewDeviceCard::NewDeviceCard(QWidget *parent, int width, int height)
    : QWidget(parent), m_width(width), m_height(height)
{
    setFixedSize(width, height);
    setupUI();

    connect(m_newButton, &QPushButton::clicked, this, &NewDeviceCard::createNewDevice);
}

void NewDeviceCard::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Container widget
    m_containerWidget = new QWidget(this);
    m_containerWidget->setObjectName("containerWidget");
    m_containerWidget->setFixedSize(m_width, m_height);

    QVBoxLayout *containerLayout = new QVBoxLayout(m_containerWidget);
    containerLayout->setContentsMargins(10, 10, 10, 10);
    containerLayout->setSpacing(10);

    // Plus sign in center
    m_plusLabel = new QLabel(m_containerWidget);
    m_plusLabel->setObjectName("plusLabel");
    m_plusLabel->setText("+");
    m_plusLabel->setAlignment(Qt::AlignCenter);
    m_plusLabel->setStyleSheet("font-size: 80px; color: white;");

    // New button at bottom
    m_newButton = new QPushButton("新建", m_containerWidget);
    m_newButton->setObjectName("newButton");
    m_newButton->setFixedHeight(30);

    containerLayout->addStretch();
    containerLayout->addWidget(m_plusLabel);
    containerLayout->addStretch();
    containerLayout->addWidget(m_newButton, 0, Qt::AlignCenter);

    mainLayout->addWidget(m_containerWidget);


    QFile file(":/styles/devicecard.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = QLatin1String(file.readAll());
        setStyleSheet(styleSheet);
        file.close();
    }
}

bool NewDeviceCard::event(QEvent *event)
{
    if (event->type() == QEvent::Enter) {
        // Change background color on hover - handled via stylesheet
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
        emit createNewDevice();
        return true;
    }

    return QWidget::event(event);
}
